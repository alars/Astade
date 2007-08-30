indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

for (int isStatic=0; isStatic<2; isStatic++)
{
	dc.Clear();
	dc.DrawBitmap(AstadeIcons::GetAttributeIcon(),0,0,true);
	if (isStatic==0)
		dc.DrawBitmap(AstadeIcons::GetStaticIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetPublicIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

	dc.Clear();
	dc.DrawBitmap(AstadeIcons::GetAttributeIcon(),0,0,true);
	if (isStatic==0)
		dc.DrawBitmap(AstadeIcons::GetStaticIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetProtectedIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

	dc.Clear();
	dc.DrawBitmap(AstadeIcons::GetAttributeIcon(),0,0,true);
	if (isStatic==0)
		dc.DrawBitmap(AstadeIcons::GetStaticIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetPrivateIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
}