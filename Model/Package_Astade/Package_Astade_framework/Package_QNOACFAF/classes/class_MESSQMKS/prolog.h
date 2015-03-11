#include <ostream>

#define DECLARE_PORT(p) \
    public slots: void p ##_1(const AQF_Message& event){static QString port(#p);TakeEvent(port,event);}; \
    signals: void p ##_2(const AQF_Message&); \
    public: AQF_MessageReceiver* p ##_3;

#define CONNECT_PORTS(a,b,c,d) a.PortConnect(#b,#d,c,b ## _3,d ## _3);