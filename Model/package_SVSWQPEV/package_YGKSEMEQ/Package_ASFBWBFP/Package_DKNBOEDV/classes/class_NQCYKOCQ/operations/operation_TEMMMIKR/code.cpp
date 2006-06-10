int w,h;
GetSize(&w,&h);

if (m_MouseOver)
{
	dc.SetBrush(*wxRED);
	dc.DrawEllipse((-w/2)+m_Position.xCoord(),(-h/2)+m_Position.yCoord(),w,h);
}
else
	dc.SetBrush(*wxLIGHT_GREY);

dc.DrawCircle(m_Position.xCoord(),m_Position.yCoord()-29,9);
dc.DrawLine(m_Position.xCoord(),m_Position.yCoord()-20,m_Position.xCoord(),m_Position.yCoord());

dc.DrawLine(m_Position.xCoord()-15,m_Position.yCoord()-15,m_Position.xCoord()+15,m_Position.yCoord()-15);

dc.DrawLine(m_Position.xCoord(),m_Position.yCoord(),m_Position.xCoord()+15,m_Position.yCoord()+15);
dc.DrawLine(m_Position.xCoord(),m_Position.yCoord(),m_Position.xCoord()-15,m_Position.yCoord()+15);

dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_Position.xCoord()-(w/2),m_Position.yCoord()+15);

for (std::set<GrafUseCase*>::iterator it = myGrafUseCase.begin(); it != myGrafUseCase.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector r1 = GetBorderPoint(p2);
	GrafVector r2 = (*it)->GetBorderPoint(p1);

	dc.DrawLine(r1.xCoord(),r1.yCoord(),r2.xCoord(),r2.yCoord());
}