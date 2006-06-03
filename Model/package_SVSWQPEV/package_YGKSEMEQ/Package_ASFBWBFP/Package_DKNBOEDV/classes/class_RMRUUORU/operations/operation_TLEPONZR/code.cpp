if (m_MouseOver)
	dc.SetBrush(*wxRED);
else
	dc.SetBrush(*wxLIGHT_GREY);

if (m_Parent->IsSelected(this))
{
	dc.SetBrush(*wxBLUE);
}

int w,h;
GetSize(&w,&h);
dc.DrawEllipse((-w/2)+m_Position.xCoord(),(-h/2)+m_Position.yCoord(),w,h);

if (m_Parent->IsSelected(this))
{
	wxPoint p = m_Parent->ScreenToClient(wxGetMousePosition());
	dc.DrawLine(m_Position.xCoord(),m_Position.yCoord(),p.x,p.y);
}
