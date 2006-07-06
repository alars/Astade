GrafNode::Refresh();

wxRect dirty1(m_OldDrawPosition.xCoord()-(m_LabelWidth/2),m_OldDrawPosition.yCoord()+15,m_LabelWidth,m_LabelHight);
wxRect dirty2(m_DrawPosition.xCoord()-(m_LabelWidth/2),m_DrawPosition.yCoord()+15,m_LabelWidth,m_LabelHight);

dirty1.Union(dirty2);
m_Parent->RefreshRect(dirty1);
m_Parent->RefreshEdge(this);
