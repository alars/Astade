#include "ACF.h"
#include "crossroadCapsule.h"

int main(int argc, char** argv)
{
    ACF anACF;
    crossroadCapsule topCapsule(&anACF);
    ACF_init();
	ACF_lastTime = ACF_getTimeTick();
    topCapsule.Initialize();
    
	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
