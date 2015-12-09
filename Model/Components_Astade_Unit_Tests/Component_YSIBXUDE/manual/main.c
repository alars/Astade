#include "ACF.h"
#include "test_capsule.h"

int main(int argc, char** argv)
{
    ACF anACF;
    
    ACF_init();
    
    test_capsule topCapsule;
    test_capsule_Constructor(&topCapsule, &anACF);
    test_capsule_Initialize(&topCapsule);
    
 	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
