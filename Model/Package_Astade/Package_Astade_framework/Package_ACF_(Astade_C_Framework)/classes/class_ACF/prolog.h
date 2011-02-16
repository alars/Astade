//declare the macros for the port concept
#define DECLARE_PORT(port) ACF_MessageReceiver* port;
#define CONNECT_PORTS(inObject, inPort, outObject, outPort) outPort = (ACF_MessageReceiver*)&inObject; inPort = (ACF_MessageReceiver*)&outObject;
