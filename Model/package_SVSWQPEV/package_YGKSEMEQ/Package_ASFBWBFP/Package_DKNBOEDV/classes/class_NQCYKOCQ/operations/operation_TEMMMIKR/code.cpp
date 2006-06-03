if (m_MouseOver)
	dc.SetBrush(*wxBLUE);
else
	dc.SetBrush(*wxCYAN);

int w,h;
GetSize(&w,&h);
dc.DrawEllipse((-w/2)+m_Position.xCoord(),(-h/2)+m_Position.yCoord(),w,h);