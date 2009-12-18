#include "ACF.h"
#include "trigger.h"
#include "trigger_impl.h"

int main(int argc, char** argv)
{
    int i;
    trigger aTrigger;
    trigger_impl aTrigger_impl;

    trigger_Initialize(&aTrigger, &aTrigger_impl, 0, (char*)"horst", 1);
    
 	//call the endless loop of the framework
	//ACF_loop();
    
    for (i=0; i < 500000; i++)
        ACF_handleMessage();
        
	return 0;
}
