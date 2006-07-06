GrafVector p1 = myStartNode.GetDrawPosition();
GrafVector p2 = myEndNode.GetDrawPosition();

GrafVector r1 = myStartNode.GetBorderPoint(p2);
GrafVector r2 = myEndNode.GetBorderPoint(p1);


wxRect dirty1(wxPoint(r1.xCoord(),r1.yCoord()),wxPoint(r2.xCoord(),r2.yCoord()));
dirty1.Inflate(15,15);

dirty1.Union(m_OldDrawRect);
myStartNode.GetParent()->RefreshRect(dirty1);


// calculating textposition
if (!m_Label.empty())
{
	int startX = r1.xCoord();
	int stopX = r2.xCoord();
	int startY = r1.yCoord();
	int stopY = r2.yCoord();

	wxCoord w = m_LabelWidth;
	wxCoord h = m_LabelHight;

	if (startX<stopX)
		w=0;

	if (startY<stopY)
		h=0;

	wxRect dirty = wxRect(startX-w,startY-h,m_LabelWidth,m_LabelHight);
	myStartNode.GetParent()->RefreshRect(m_OldLabelRect);
	myStartNode.GetParent()->RefreshRect(dirty);
}