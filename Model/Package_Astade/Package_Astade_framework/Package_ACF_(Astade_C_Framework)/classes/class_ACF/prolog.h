//declare the macros for the port concept
#define DECLARE_PORT(port) ACF_MessageReceiver* port;
#define CONNECT_PORTS(inObject, inPort, outObject, outPort) outPort = &inObject; inPort = &outObject;