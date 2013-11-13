//declare the macros for the port concept
#define DECLARE_PORT(port) ACF_MessageReceiver* port;
#define CONNECT_CPORTS(inObject, inPort, outObject, outPort) outPort = (ACF_MessageReceiver*)&inObject; inPort = (ACF_MessageReceiver*)&outObject;
#define CONNECT_PORTS(inObject, inPort, outObject, outPort) outPort = inObject.MessageReceiver(); inPort = outObject.MessageReceiver();
#define CONNECT_CPORT(inObject, outObject, outPort) outPort = (ACF_MessageReceiver*)&inObject;
#define CONNECT_PORT(inObject, outObject, outPort) outPort = inObject.MessageReceiver();
