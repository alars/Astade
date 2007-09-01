indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetRelationIcon().ConvertToImage().Mirror(false)),0,0,true);
dc.DrawBitmap(AstadeIcons::GetCppIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetRelationIcon().ConvertToImage().Mirror(false)),0,0,true);
dc.DrawBitmap(AstadeIcons::GetHIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetRelationIcon().ConvertToImage().Mirror(false)),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetAssociationIcon().ConvertToImage().Mirror(false)),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetAgregationIcon().ConvertToImage().Mirror(false)),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetCompositionIcon().ConvertToImage().Mirror(false)),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

dc.Clear();
dc.DrawBitmap(wxBitmap(AstadeIcons::GetGeneralisationIcon().ConvertToImage().Mirror(false)),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));