GrafNode::OnDraw(dc);

int w,h;
GetSize(&w,&h);

if (m_MouseOver)
{
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
}
else
{
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),1,wxSOLID));
}

dc.DrawCircle(m_DrawPosition.xCoord(),m_DrawPosition.yCoord()-29,9);
dc.DrawLine(m_DrawPosition.xCoord(),m_DrawPosition.yCoord()-20,m_DrawPosition.xCoord(),m_DrawPosition.yCoord());

dc.DrawLine(m_DrawPosition.xCoord()-15,m_DrawPosition.yCoord()-15,m_DrawPosition.xCoord()+15,m_DrawPosition.yCoord()-15);

dc.DrawLine(m_DrawPosition.xCoord(),m_DrawPosition.yCoord(),m_DrawPosition.xCoord()+15,m_DrawPosition.yCoord()+15);
dc.DrawLine(m_DrawPosition.xCoord(),m_DrawPosition.yCoord(),m_DrawPosition.xCoord()-15,m_DrawPosition.yCoord()+15);

wxString label = myLabel->GetValue();
dc.GetTextExtent(label,&m_LabelWidth,&m_LabelHight);
dc.DrawText(label,m_DrawPosition.xCoord()-(m_LabelWidth/2),m_DrawPosition.yCoord()+15);

for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
	(*it)->OnDraw(dc);

for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
	(*it)->OnDraw(dc);