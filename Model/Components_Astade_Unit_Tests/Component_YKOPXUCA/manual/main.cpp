#include <QApplication>
#include "../auto/trigger_impl.h"
#include "../auto/Trace2UML.h"

int main(int argc, char** argv)
{
    Trace2UML::ms_ofile.open("Trace2UML.seq");
    QApplication app(argc, argv);
    trigger_impl t;
    t.m_tracefile = &Trace2UML::ms_ofile;
    t.Initialize();
    return app.exec(); 
}
