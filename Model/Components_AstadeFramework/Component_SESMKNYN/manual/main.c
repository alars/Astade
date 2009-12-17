#include "ACF.h"
#include "simple.h"

int main(int argc, char** argv)
{
    simple test;
    simple_Constructor(&test,(char*)"aSimple",0,1);
    simple_Destructor(&test);
	//call the endless loop of the framework
	//ACF_loop(); 
	return 0;
}
