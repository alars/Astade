#include "ACF.h"
#include "implement_gustav.h"

int main(int argc, char** argv)
{
    ACF_init();
	ACF_lastTime = ACF_getTimeTick();
    
    implement_gustav aMachine;
    
    aMachine.Initialize(0);
    
	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
