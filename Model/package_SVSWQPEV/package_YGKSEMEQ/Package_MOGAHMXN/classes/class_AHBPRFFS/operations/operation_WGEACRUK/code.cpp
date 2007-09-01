indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetRelationIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetCppIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetRelationIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetHIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetRelationIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetAssociationIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetAgregationIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetCompositionIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetGeneralisationIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));