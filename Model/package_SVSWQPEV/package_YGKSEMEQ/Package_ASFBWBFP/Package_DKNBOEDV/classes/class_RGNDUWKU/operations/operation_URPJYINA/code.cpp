int w,h;
GetSize(&w,&h);

wxRect dirty1(m_OldDrawPosition.xCoord()-(w/2),m_OldDrawPosition.yCoord()-(h/2),w,h);
dirty1.Inflate(2,2);

wxRect dirty2(m_DrawPosition.xCoord()-(w/2),m_DrawPosition.yCoord()-(h/2),w,h);

m_Parent->RefreshRect(dirty2,false);
m_Parent->RefreshRect(dirty1);