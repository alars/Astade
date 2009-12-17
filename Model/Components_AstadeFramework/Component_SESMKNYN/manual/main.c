#include "ACF.h"
#include "simple.h"

int main(int argc, char** argv)
{
    int i;
    simple test1, test2, test3;
    simple_Constructor(&test1,(char*)"aSimple1",0,1);
    simple_Constructor(&test2,(char*)"aSimple2",0,1);
    simple_Constructor(&test3,(char*)"aSimple3",0,1);
 	//call the endless loop of the framework
	//ACF_loop();
    
    ACF_sendMessage(0,(ACF_MessageReceiver*)&test1,(char*)"test",5,0);
    ACF_scheduleTimeout((ACF_MessageReceiver*)&test1,10);
    ACF_scheduleTimeout((ACF_MessageReceiver*)&test2,20);
    ACF_scheduleTimeout((ACF_MessageReceiver*)&test3,15);

    for (i=0; i < 500000; i++)
        ACF_handleMessage();
        
    simple_Destructor(&test1);
    simple_Destructor(&test2);
    simple_Destructor(&test3);
	return 0;
}
