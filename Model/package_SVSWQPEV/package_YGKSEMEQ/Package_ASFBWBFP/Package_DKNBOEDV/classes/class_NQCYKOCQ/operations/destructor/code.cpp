for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
	delete *it;

for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
	delete *it;

delete myLabel;
wxRect dirty1(m_OldDrawPosition.xCoord()-(m_LabelWidth/2),m_OldDrawPosition.yCoord()+15,m_LabelWidth,m_LabelHight);
m_Parent->RefreshRect(dirty1);

int w,h;
GetSize(&w,&h);
wxRect dirty2(m_OldDrawPosition.xCoord()-(w/2),m_OldDrawPosition.yCoord()-(h/2),w,h);
dirty2.Inflate(2,2);
m_Parent->RefreshRect(dirty2);