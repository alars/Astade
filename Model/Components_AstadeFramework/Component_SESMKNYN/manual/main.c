#include "ACF.h"
#include "trigger.h"
#include "trigger_impl.h"
#include "TickTackToe.h"
#include "TickTackToe_impl.h"

int main(int argc, char** argv)
{
/*
    ACF_init();

    while (1)
    {
        int i,j;
        ACF_trace("DIES IST EIN TEST\n");   
        for (j=0; j<30000; j++)
        for (i=0; i<30000; i++)
            if (i==j)
                j++;
    }
*/    
    trigger aTrigger;
    trigger_impl aTrigger_impl;
    TickTackToe aTickTackToe;
    TickTackToe_impl aTickTackToe_impl;
    
    ACF_init();
    
    trigger_impl_Constructor(&aTrigger_impl, (ACF_MessageReceiver*)&aTickTackToe);

    TickTackToe_Initialize(&aTickTackToe, &aTickTackToe_impl, 0, (char*)"Willi", 1);
    trigger_Initialize(&aTrigger, &aTrigger_impl, 0, (char*)"horst", 1);
    
 	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
