indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);


for (int inLine = 0; inLine < 2; inLine++)
{
	//static
	dc.Clear();
	dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetStaticIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetPublicIcon(),0,0,true);
	if (inLine == 1)
		dc.DrawBitmap(AstadeIcons::GetInlineIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

	dc.Clear();
	dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetStaticIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetProtectedIcon(),0,0,true);
	if (inLine == 1)
		dc.DrawBitmap(AstadeIcons::GetInlineIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

	dc.Clear();
	dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetStaticIcon(),0,0,true);
	dc.DrawBitmap(AstadeIcons::GetPrivateIcon(),0,0,true);
	if (inLine == 1)
		dc.DrawBitmap(AstadeIcons::GetInlineIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
	AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

	// non static
	for (int isVirtual=0; isVirtual<3; isVirtual++)
	{
		dc.Clear();
		dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
		dc.DrawBitmap(AstadeIcons::GetPublicIcon(),0,0,true);
		if (isVirtual==1)
			dc.DrawBitmap(AstadeIcons::GetVirtualIcon(),0,0,true);
		if (isVirtual==2)
			dc.DrawBitmap(AstadeIcons::GetAbstractIcon(),0,0,true);
		if (inLine == 1)
			dc.DrawBitmap(AstadeIcons::GetInlineIcon(),0,0,true);
		AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
		dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
		AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

		dc.Clear();
		dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
		dc.DrawBitmap(AstadeIcons::GetProtectedIcon(),0,0,true);
		if (isVirtual==1)
			dc.DrawBitmap(AstadeIcons::GetVirtualIcon(),0,0,true);
		if (isVirtual==2)
			dc.DrawBitmap(AstadeIcons::GetAbstractIcon(),0,0,true);
		if (inLine == 1)
			dc.DrawBitmap(AstadeIcons::GetInlineIcon(),0,0,true);
		AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
		dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
		AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));

		dc.Clear();
		dc.DrawBitmap(AstadeIcons::GetOperationIcon(),0,0,true);
		dc.DrawBitmap(AstadeIcons::GetPrivateIcon(),0,0,true);
		if (isVirtual==1)
			dc.DrawBitmap(AstadeIcons::GetVirtualIcon(),0,0,true);
		if (isVirtual==2)
			dc.DrawBitmap(AstadeIcons::GetAbstractIcon(),0,0,true);
		if (inLine == 1)
			dc.DrawBitmap(AstadeIcons::GetInlineIcon(),0,0,true);
		AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
		dc.DrawBitmap(AstadeIcons::GetConstIcon(),0,0,true);
		AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
	}
}