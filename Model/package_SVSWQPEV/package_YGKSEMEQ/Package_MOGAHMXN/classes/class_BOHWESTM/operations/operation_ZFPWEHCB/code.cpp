wxIcon aIcon;

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(wxBitmap(wxBitmap(XPM_Data).ConvertToImage().Rescale(ASTADEICONHIGHT,ASTADEICONHIGHT)),4,0,true);

aIcon.CopyFromBitmap(wxBitmap(aBitmap.ConvertToImage()));
return aIcon;