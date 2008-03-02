using namespace std; 
#include <stdio.h>
#include "HelloClass1.h"

int main(int argc, char** argv)
{ 
    printf("Generating an object\n");
    HelloClass1* obj1 = new HelloClass1;
    
    printf("Call a static operation\n");
    HelloClass1_Test1();

    printf("Call a normal operation\n");
    HelloClass1_Test2(obj1); // don't forget to pass the "me" pointer ;-)

    return 0;
}
