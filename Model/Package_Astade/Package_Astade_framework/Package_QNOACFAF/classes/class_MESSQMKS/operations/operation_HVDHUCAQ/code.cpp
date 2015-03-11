//~~ void PortConnect(const char* ownOut, const char* otherIn, AQF_MessageReceiver& otherObject, ACF_MessageReceiver*& out, ACF_MessageReceiver*& in) [AQF_MessageReceiver] ~~
QString p1(ownOut);
p1.remove(0,p1.indexOf('.')+1);
QString p2(otherIn);
p2.remove(0,p2.indexOf('.')+1);

printf("portnames are <%s> and <%s>\n",p1.toLocal8Bit().data(),p2.toLocal8Bit().data());

connect(this, (QString("2")+p1+QString("_2")).toLocal8Bit().data(),
        &otherObject, (QString("1")+p2+QString("_1")).toLocal8Bit().data());
        
connect(&otherObject, (QString("2")+p2+QString("_2")).toLocal8Bit().data(),
        this, (QString("1")+p1+QString("_1")).toLocal8Bit().data());
        
out = &otherObject;
in = this;