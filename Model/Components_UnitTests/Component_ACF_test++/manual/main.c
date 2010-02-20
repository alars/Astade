#include "ACF.h"
#include "implementGustav.h"

const char* hasenfurz = "hasenfurz";

int main(int argc, char** argv)
{
    ACF_init();
	ACF_lastTime = ACF_getTimeTick();
    
    implementGustav aMachine;
    
    aMachine.Initialize(0);
    
	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
