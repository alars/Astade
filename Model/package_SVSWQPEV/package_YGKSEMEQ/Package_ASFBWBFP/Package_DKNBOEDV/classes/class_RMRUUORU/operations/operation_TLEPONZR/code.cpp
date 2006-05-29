if (m_MouseOver)
	dc.SetBrush(*wxRED);
else
	dc.SetBrush(*wxBLUE);
dc.DrawEllipse(GetSize());