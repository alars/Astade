indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

for (int i = 0; i<2; i++)
{
    dc.Clear();
    dc.DrawBitmap(AstadeIcons::GetClassIcon(),0,0,true);
    if (i==1)
        dc.DrawBitmap(AstadeIcons::GetCIcon(),0,0,true);
        
    AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
 
    dc.DrawBitmap(AstadeIcons::GetBelongingIcon(),0,0,true);
    if (i==1)
        dc.DrawBitmap(AstadeIcons::GetCIcon(),0,0,true);
        
    AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

    dc.Clear();
    dc.DrawBitmap(AstadeIcons::GetClassIcon(),0,0,true);
    dc.DrawBitmap(AstadeIcons::GetChangedIcon(),0,0,true);
    if (i==1)
        dc.DrawBitmap(AstadeIcons::GetCIcon(),0,0,true);
        
    AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

    dc.Clear();
    dc.DrawBitmap(AstadeIcons::GetClassIcon(),0,0,true);
    dc.DrawBitmap(AstadeIcons::GetLibIcon(),0,0,true);
    if (i==1)
        dc.DrawBitmap(AstadeIcons::GetCIcon(),0,0,true);

    AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
        
    dc.Clear();
    dc.DrawBitmap(AstadeIcons::GetClassIcon(),0,0,true);
    dc.DrawBitmap(AstadeIcons::GetAttentionIcon(),0,0,true);
    if (i==1)
        dc.DrawBitmap(AstadeIcons::GetCIcon(),0,0,true);
        
    AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
}