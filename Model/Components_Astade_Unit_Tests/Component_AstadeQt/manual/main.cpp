#include <QApplication>
#include "../auto/TickTackToeCapsule.h"
#include "../auto/Trace2UML.h"

int main(int argc, char** argv)
{
    Trace2UML::ms_ofile.open("Trace2UML.seq");
    QApplication app(argc, argv);
    TickTackToeCapsule c;
    c.Initialize();
    return app.exec(); 
}
