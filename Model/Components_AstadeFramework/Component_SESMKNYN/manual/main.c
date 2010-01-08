#include "ACF.h"
#include "trigger_impl.h"
#include "TickTackToe_impl.h"

int main(int argc, char** argv)
{
    trigger_impl aTrigger_impl;
    TickTackToe_impl aTickTackToe_impl;
    
    ACF_init();
    
    trigger_impl_Constructor(&aTrigger_impl, (ACF_MessageReceiver*)&aTickTackToe_impl);
    TickTackToe_impl_Constructor(&aTickTackToe_impl);

    TickTackToe_Initialize(&aTickTackToe_impl.TickTackToe_base, 0, (char*)"hugo", 1);
    trigger_Initialize(&aTrigger_impl.trigger_base, 0, (char*)"horst", 1);
    
 	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
