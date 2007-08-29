indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetConstructorIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetPublicIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetConstructorIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetProtectedIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetConstructorIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetPrivateIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
