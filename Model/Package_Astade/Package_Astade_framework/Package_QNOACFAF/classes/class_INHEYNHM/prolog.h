// Author: t.spitzer@astade.de
// Year: 2014

#ifndef HEADER_480EE7A85E094D17B10707DE581FDE7E
#define HEADER_480EE7A85E094D17B10707DE581FDE7E


#include <fstream>
#include <iostream>
#include <istream>
#include <semaphore.h>
#include <QObject>
#include <QString>

/** A Trace helper class to generate traces in Trace2UML formate
*/
class Trace2UML
{

public:
/** only trace operations with level > tracelevel
*/
    static int	tracelevel;

/** The output file
*/
    static std::ofstream	ms_ofile;

/** use this to notify a message receive
@param sourcePointer The pointer of the source object
@param sourceName The classname of the source object
@param destinationPointer The pointer of the destination object
@param destinationName The classname of the destination object
@param eventName The name of the received event
*/
    static void notify_message_received(const void* sourcePointer, const char* sourceName, const void* destinationPointer, const char* destinationName, const char* eventName);

/** use this to notify a message sent
@param sourcePointer The pointer of the source object
@param sourceName The classname of the source object
@param destinationPointer The pointer of the destination object
@param destinationName The classname of the destination object
@param eventName The name of the received event
*/
    static void notify_message_sent(const void* sourcePointer, const char* sourceName, const void* destinationPointer, const char* destinationName, const char* eventName);

/** static function to add a statechange trace entry
@param level only trace operations with level > tracelevel
@param objectPointer a uniqe identifier to the traced object. We use the address of the object as it is unique
@param objectName The classname of the traced object
@param stateName The name of the new state
*/
    static void notify_state(int level, const void* objectPointer, const char* objectName, const char* stateName);

/** sets the internal variable to write to toe return arrow
@param aRetVal the return value
*/
    bool setRetval(bool aRetVal);

/** sets the internal variable to write to toe return arrow
@param aRetVal the return value
*/
    const std::string& setRetval(const std::string& aRetVal);

/** sets the internal variable to write to toe return arrow
@param aRetVal the return value
*/
    int setRetval(int aRetVal);

/** sets the internal variable to write to  return arrow
@param aRetVal the return value
*/
    long setRetval(long aRetVal);

/** sets the internal variable to write to the return arrow
@param aRetVal the return value
*/
    std::string& setRetval(std::string& aRetVal);

/** sets the internal variable to write to toe return arrow
@param aRetVal the return value
*/
unsigned int setRetval(unsigned int aRetVal);

/** sets the internal variable to write to  return arrow
@param aRetVal the return value
*/
QString& setRetval(QString& aRetVal);

/** sets the internal variable to write to  return arrow
@param aRetVal the return value
*/
const QString& setRetval(const QString& aRetVal);

/** sets the internal variable to write to  return arrow
@param aRetVal the return value
*/
unsigned long setRetval(unsigned long aRetVal);

/** The constructor writes the call trace entry
@param notificationType The type of notificatification (call, constructor, destructor, selfcall)
@param level only trace operations with level > tracelevel
@param objectPointer a uniqe identifier to the traced object. We use the address of the object as it is unique
@param objectName The classname of the traced object
@param parameterList A text which describes the parameterlist
@param functionName The name of the called function
@pre notificationType >= 0 && notificationType<=3
*/
    Trace2UML(int notificationType, int level, const void* objectPointer, const char* objectName, const char* parameterList = 0, const char* functionName = 0);

/** The destructor writes the return trace entry
*/
    ~Trace2UML();

static void InsertConnection(QObject* sourcePtr, const QString& sourcePort, QObject* destPtr, const QString& destPort);
static void notifySignal(void* sourcePtr, const char* sourcePort);
static void notifySlot (void* destPtr, const char *destPort);

protected:

private:
/** synchronizes the trace map
*/
    static sem_t	msSemaphore;

/** to cache the opject name
*/
    std::string m_objname;

/** to cache the this ptr
*/
    const void* m_this;

/** The trace level of this object (to compare with "tracelevel")
*/
    int	m_level;

/** The type of notification which created this object
*/
    int	m_NotificationType;

/** The name of the previous running object
*/
    const char*	m_PreviousRunningObject;

/** The unique ID of the previously running object
*/
    const void*	m_PreviousRunningObjectPointer;

/** the text to write onto the return arrow
*/
    std::string	retval;

/** traces a timestamp
*/
    static void traceTimestamp();
};


#ifdef _TRACE_

#  define RETURN(VAL) return NOTIFY_FUNCTION_CALL_Helper.setRetval(VAL);
#  define NOTIFY_FUNCTION_CALL(ID,LEVEL,CLASS,FUNCTION,PARAMETER,RETURN) Trace2UML NOTIFY_FUNCTION_CALL_Helper(1,LEVEL,ID,CLASS,PARAMETER,FUNCTION);
#  define NOTIFY_CONSTRUCTOR(LEVEL,CLASS,PARAMETER) Trace2UML NOTIFY_FUNCTION_CALL_Helper(0,LEVEL,this,CLASS,PARAMETER);
#  define NOTIFY_DESTRUCTOR(LEVEL,CLASS) Trace2UML NOTIFY_FUNCTION_CALL_Helper(2,LEVEL,this,CLASS);
#  define NOTIFY_CONNECT(sourcePtr, sourcePort, destPtr, destPort) Trace2UML::InsertConnection(sourcePtr, sourcePort, destPtr, destPort);connect(sourcePtr, sourcePort, destPtr, destPort);
#  define NOTIFY_CONNECT2(sourcePtr, sourcePort, destPtr, destPort, connType) Trace2UML::InsertConnection(sourcePtr, sourcePort, destPtr, destPort);connect(sourcePtr, sourcePort, destPtr, destPort, connType);
#  define NOTIFY_SIGNAL(sourcePtr, sourcePort) Trace2UML::notifySignal(sourcePtr, sourcePort);
#  define NOTIFY_SLOT(destPtr, destPort) Trace2UML::notifySlot(destPtr, destPort);

#else

#  define RETURN(VAL) return(VAL);
#  define NOTIFY_FUNCTION_CALL(ID,LEVEL,CLASS,FUNCTION,PARAMETER,RETURN);
#  define NOTIFY_CONSTRUCTOR(LEVEL,CLASS,PARAMETER);
#  define NOTIFY_DESTRUCTOR(LEVEL,CLASS);
#  define NOTIFY_CONNECT(sourcePtr, sourcePort, destPtr, destPort) connect(sourcePtr, sourcePort, destPtr, destPort);
#  define NOTIFY_CONNECT2(sourcePtr, sourcePort, destPtr, destPort, connType) connect(sourcePtr, sourcePort, destPtr, destPort, connType);
#  define NOTIFY_SIGNAL(sourcePtr, sourcePort);
#  define NOTIFY_SLOT(destPtr, destPort);

#endif

#endif /* HEADER_480EE7A85E094D17B10707DE581FDE7E */