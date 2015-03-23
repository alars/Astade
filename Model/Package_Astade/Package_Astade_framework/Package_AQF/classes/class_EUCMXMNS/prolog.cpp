#include "Trace2UML.h"

#include <stdio.h>
#include <stdarg.h>

#include <QThread>
#include <QDateTime>

int	Trace2UML::tracelevel = 0;

std::ofstream	Trace2UML::ms_ofile;

sem_t	Trace2UML::msSemaphore;

void Trace2UML::notify_message_received(const void* sourcePointer, const char* sourceName, const void* destinationPointer, const char* destinationName, const char* eventName)
{
    if ((destinationPointer == 0) || (destinationName == 0) || (eventName == 0))
        return;

    while (sem_wait(&msSemaphore))
        ;

    traceTimestamp();

    if ((sourcePointer == 0) || sourceName == 0)
    {
        ms_ofile << "~ --> " << destinationPointer << ":" << destinationName << " " << eventName << std::endl;
    }
    else
    {
        ms_ofile << sourcePointer << ":" << sourceName << " --> " << destinationPointer << ":" << destinationName << " " << eventName << std::endl;
    }

    ms_ofile.flush();
    sem_post(&msSemaphore);
}

void Trace2UML::notify_message_sent(const void* sourcePointer, const char* sourceName, const void* destinationPointer, const char* destinationName, const char* eventName)
{
    if ((sourcePointer == 0) || (sourceName == 0) || (destinationPointer == 0) || (destinationName == 0) || (eventName == 0))
        return;

    while (sem_wait(&msSemaphore))
        ;

    traceTimestamp();

    ms_ofile << sourcePointer << ":" << sourceName << " >-- " << destinationPointer << ":" << destinationName << " " << eventName << std::endl;

    ms_ofile.flush();
    sem_post(&msSemaphore);
}

void Trace2UML::notify_state(int level, const void* objectPointer, const char* objectName, const char* stateName)
{
    while (sem_wait(&msSemaphore))
        ;

    if (level > tracelevel && ms_ofile.is_open())
    {
        traceTimestamp();
        ms_ofile << objectPointer << ":" << objectName << " >>> " << stateName << std::endl;
    }

    ms_ofile.flush();
    sem_post(&msSemaphore);
}

void Trace2UML::note(int level, const void* objectPointer, const char* objectName, const char* format, ...)
{
    va_list arg;

    while (sem_wait(&msSemaphore))
        ;

    if (level > tracelevel && ms_ofile.is_open())
    {
        char buffer[1024];

        traceTimestamp();
        va_start(arg, format);
        vsprintf(buffer, format, arg);
        va_end(arg);
        ms_ofile << objectPointer << ":" << objectName << " note: " << buffer << std::endl;
    }

    ms_ofile.flush();
    sem_post(&msSemaphore);
}

bool Trace2UML::setRetval(bool aRetVal)
{
    if (aRetVal)
        retval = "true";
    else
        retval = "false";

    return aRetVal;
}

const std::string& Trace2UML::setRetval(const std::string& aRetVal)
{
    std::string a("\"");
    std::string sub = aRetVal.substr(0,15);

    for (unsigned i = 0; i < sub.size(); i++) {
        if (sub[i]<=0x20)
            sub[i] = '?';
    }

    if (sub.size() < aRetVal.size())
        sub += "...";

    retval = a + aRetVal + a;
    return aRetVal;
}

int Trace2UML::setRetval(int aRetVal)
{
    char buffer[24];
    sprintf(buffer, "%d", aRetVal);
    retval = buffer;

    return aRetVal;
}

long Trace2UML::setRetval(long aRetVal)
{
    char buffer[24];
    sprintf(buffer, "%ld", aRetVal);
    retval = buffer;

    return aRetVal;
}

std::string& Trace2UML::setRetval(std::string& aRetVal)
{
    std::string a("\"");
    retval = a + aRetVal + a;
    return aRetVal;
}

QString& Trace2UML::setRetval(QString& aRetVal)
{
    std::string a("\"");
    retval = a + aRetVal.toStdString() + a;
    return aRetVal;
}

const QString& Trace2UML::setRetval(const QString& aRetVal)
{
    std::string a("\"");
    retval = a + aRetVal.toStdString() + a;
    return aRetVal;
}

unsigned int Trace2UML::setRetval(unsigned int aRetVal)
{
    char buffer[24];
    sprintf(buffer, "%u", aRetVal);
    retval = buffer;

    return aRetVal;
}

unsigned long Trace2UML::setRetval(unsigned long aRetVal)
{
    char buffer[24];
    sprintf(buffer, "%lu", aRetVal);
    retval = buffer;

    return aRetVal;
}

static bool sem_initialzed = false;

Trace2UML::Trace2UML(int notificationType, int level, const void* objectPointer, const char* objectName, const char* parameterList, const char* functionName) :
    m_objname(objectName),
    m_this(objectPointer),
    m_level(level),
    m_NotificationType(notificationType)
{
    if (!sem_initialzed)
    {
        sem_init(&msSemaphore, 0, 1);
        sem_initialzed = true;
    }

    while (sem_wait(&msSemaphore))
        ;

    if (m_level > tracelevel && ms_ofile.is_open())
    {
        const char* flag = NULL;
        switch (m_NotificationType)
        {
            case 0:
                flag = "+";
                break;

            case 1:
            case 3:
                flag = ">";
                break;

        }
        if (flag)
        {
            traceTimestamp();
            ms_ofile << flag;
            if (m_this)
                ms_ofile << m_this << ":";

            ms_ofile << m_objname;

            if (m_NotificationType == 1)
                    ms_ofile << " " << functionName << "(" << parameterList << ")";

            ms_ofile << std::endl;
            ms_ofile.flush();
        }
    }
    sem_post(&msSemaphore);
}

Trace2UML::~Trace2UML()
{
    while (sem_wait(&msSemaphore))
        ;

    if (m_level > tracelevel && ms_ofile.is_open())
    {
        const char* flag = NULL;
        switch (m_NotificationType)
        {
            case 2:
                flag = "-";
                break;

            case 1:
            case 3:
                flag = "<";
                break;
        }
        if (flag)
        {
            traceTimestamp();
            ms_ofile << flag;
            if (m_NotificationType != 2)
            {
                if (!retval.empty())
                    ms_ofile << " " << retval;
            } else {
                if (m_this)
                    ms_ofile << m_this << ":";

                ms_ofile << m_objname;
            }
            ms_ofile << std::endl;
            ms_ofile.flush();
        }
    }

    sem_post(&msSemaphore);
}

void Trace2UML::traceTimestamp()
{
    ms_ofile << "[" << QDateTime().currentMSecsSinceEpoch() << "]{" << QThread::currentThread() << "}";
}

void Trace2UML::InsertConnection(QObject* sourcePtr, const QString& sourcePort, QObject* destPtr, const QString& destPort)
{
    if (!sem_initialzed)
    {
        sem_init(&msSemaphore, 0, 1);
        sem_initialzed = true;
    }

    while (sem_wait(&msSemaphore))
        ;

    if (ms_ofile.is_open())
    {
        const char* sourcename = sourcePtr->metaObject()->className();
        const char* ns = strstr(sourcename, "::");

        while (ns)
        {
            sourcename = ns + 2;
            ns = strstr("::",sourcename);
        }

        const char* destname = destPtr->metaObject()->className();
        ns = strstr(destname, "::");

        while (ns)
        {
            destname = ns + 2;
            ns = strstr("::",destname);
        }

        ms_ofile << "%" << sourcePtr << " " << sourcename << " " << sourcePort.toUtf8().data() << " "
                        << destPtr   << " " << destname   << " " << destPort.toUtf8().data() << std::endl;
        ms_ofile.flush();
    }

    sem_post(&msSemaphore);
}

void Trace2UML::notifySlot(void* destPtr, const char *destPort)
{
    while (sem_wait(&msSemaphore))
        ;
    Trace2UML::ms_ofile << "&" << destPtr << " " << destPort << std::endl;
    Trace2UML::ms_ofile.flush();
    sem_post(&msSemaphore);
}

void Trace2UML::notifySignal(void* sourcePtr, const char *sourcePort)
{
    while (sem_wait(&msSemaphore))
        ;
    Trace2UML::ms_ofile << "$" << sourcePtr << " " << sourcePort << std::endl;
    Trace2UML::ms_ofile.flush();
    sem_post(&msSemaphore);
}
