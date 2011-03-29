#include "Trace2UML.h"
#include "TopCapsule.h"

int main(int argc, char** argv)
{
    Trace2UML::ms_ofile.open("Trace2UML.seq");
	TopCapsule().main();
	return 0;
}
