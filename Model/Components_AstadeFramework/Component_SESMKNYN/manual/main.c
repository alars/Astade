#include "ACF.h"
#include "trigger.h"
#include "trigger_impl.h"
#include "TickTackToe.h"
#include "TickTackToe_impl.h"

int main(int argc, char** argv)
{
    int i;
    trigger aTrigger;
    trigger_impl aTrigger_impl;
    TickTackToe aTickTackToe;
    TickTackToe_impl aTickTackToe_impl;
    
    trigger_impl_Constructor(&aTrigger_impl, (ACF_MessageReceiver*)&aTickTackToe);

    TickTackToe_Initialize(&aTickTackToe, &aTickTackToe_impl, 0, (char*)"Willi", 1);
    trigger_Initialize(&aTrigger, &aTrigger_impl, 0, (char*)"horst", 1);
    
 	//call the endless loop of the framework
	//ACF_loop();
    
    for (i=0; i < 1000000; i++)
    {
//        printf("xxxxx\n");
        ACF_handleMessage();
    }
        
	return 0;
}
