if (m_MouseOver)
	dc.SetBrush(*wxRED);
else
	dc.SetBrush(*wxLIGHT_GREY);

//if (FindFocus()==this)
//	dc.SetBrush(*wxBLUE);

int w,h;
GetSize(&w,&h);
dc.DrawEllipse(0,0,w,h);