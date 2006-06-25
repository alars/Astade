GrafVector p1 = myStartNode.GetPosition();
GrafVector p2 = myEndNode.GetPosition();

GrafVector r1 = myStartNode.GetBorderPoint(p2);
GrafVector r2 = myEndNode.GetBorderPoint(p1);

dc.SetBrush(*wxWHITE);

if (myStartNode.IsMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(m_Color),2,m_LineType));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(m_Color),1,m_LineType));

DrawArrow(dc,r1.xCoord(),r1.yCoord(),r2.xCoord(),r2.yCoord(),m_ArrowHead,m_Label);