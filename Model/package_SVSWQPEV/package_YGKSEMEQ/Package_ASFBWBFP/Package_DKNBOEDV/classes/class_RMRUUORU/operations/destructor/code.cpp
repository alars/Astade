for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
	delete *it;

for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
	delete *it;

for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
	delete *it;

delete myLabel;

int w,h;
GetSize(&w,&h);
wxRect dirty1(m_OldDrawPosition.xCoord()-(w/2),m_OldDrawPosition.yCoord()-(h/2),w,h);
dirty1.Inflate(2,2);
m_Parent->RefreshRect(dirty1);