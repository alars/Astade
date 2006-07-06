GrafVector p1 = myStartNode.GetDrawPosition();
GrafVector p2 = myEndNode.GetDrawPosition();

GrafVector r1 = myStartNode.GetBorderPoint(p2);
GrafVector r2 = myEndNode.GetBorderPoint(p1);

dc.SetBrush(*wxWHITE);

if (myStartNode.IsMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(m_Color),2,m_LineType));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(m_Color),1,m_LineType));

m_OldDrawRect = wxRect(wxPoint(r1.xCoord(),r1.yCoord()),wxPoint(r2.xCoord(),r2.yCoord()));
m_OldDrawRect.Inflate(15,15);

DrawArrow(dc,r1.xCoord(),r1.yCoord(),r2.xCoord(),r2.yCoord(),m_ArrowHead,m_Label);