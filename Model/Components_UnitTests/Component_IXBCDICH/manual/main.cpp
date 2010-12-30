#include "ACF.h"

int main(int argc, char** argv)
{
    ACF_init();
	ACF_lastTime = ACF_getTimeTick();
    
	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
