#include <ostream>

#define DECLARE_PORT(p) public: AQF_MessageReceiver* p;

#define CONNECT_PORTS(inObject, inPort, outObject, outPort) outPort = &inObject; inPort = &outObject;
#define CONNECT_PORT(inObject, outObject, outPort) outPort = &inObject;
