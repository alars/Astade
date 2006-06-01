if (m_MouseOver)
	dc.SetBrush(*wxRED);
else
	dc.SetBrush(*wxLIGHT_GREY);

if (FindFocus()==this)
	dc.SetBrush(*wxBLUE);


dc.DrawEllipse(GetSize());