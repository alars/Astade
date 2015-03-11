#define DECLARE_PORT(p) \
    signals: void p ##_1(const AQF_Message&); \
    public slots: void p ##_2(const AQF_Message& event){static QString port(#p);TakeEvent(port,event);};
