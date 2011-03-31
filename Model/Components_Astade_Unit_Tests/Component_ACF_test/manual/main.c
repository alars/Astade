#include "ACF.h"
#include "trigger_impl.h"
#include "TickTackToeCapsule.h"

int main(int argc, char** argv)
{
    ACF aACF;
    
    ACF_init();
    
    TickTackToeCapsule topCapsule;
    TickTackToeCapsule_Constructor(&topCapsule, &aACF);
    TickTackToeCapsule_Initialize(&topCapsule);
    
 	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
