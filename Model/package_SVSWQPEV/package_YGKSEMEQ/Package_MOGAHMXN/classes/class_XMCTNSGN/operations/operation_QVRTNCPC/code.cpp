indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetClassIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.DrawBitmap(AstadeIcons::GetBelongingIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetClassIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetChangedIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
