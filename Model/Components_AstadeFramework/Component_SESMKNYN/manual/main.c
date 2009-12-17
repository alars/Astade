#include "ACF.h"
#include "simple.h"

int main(int argc, char** argv)
{
    int i;
    simple test;
    simple_Constructor(&test,(char*)"aSimple",0,1);
 	//call the endless loop of the framework
	//ACF_loop();
    
    ACF_sendMessage(0,(ACF_MessageReceiver*)&test,(char*)"test",5,0);
    ACF_scheduleTimeout((ACF_MessageReceiver*)&test,1);
    ACF_scheduleTimeout((ACF_MessageReceiver*)&test,2);
    
    for (i=0; i < 100000; i++)
        ACF_handleMessage();
        
    simple_Destructor(&test);
	return 0;
}
