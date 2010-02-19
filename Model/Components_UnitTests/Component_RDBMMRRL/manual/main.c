#include "ACF.h"
#include "Gustav.h"

int main(int argc, char** argv)
{
    ACF_init();
    
    Gustav aMachine;
    
    aMachine.Initialize(0);
    
	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
