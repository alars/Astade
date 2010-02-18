#include "ACF.h"

int main(int argc, char** argv)
{
    ACF_init();
    
	//call the endless loop of the framework
	ACF_loop();
	return 0;
}
