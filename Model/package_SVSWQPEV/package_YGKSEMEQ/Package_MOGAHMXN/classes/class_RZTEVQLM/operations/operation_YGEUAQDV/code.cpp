/* rebuild cache from astade.ini */
wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->SetPath("/UserApps");

wxString groupName;
long groupIndex;
wxIcon aIcon;

for(bool i=theConfig->GetFirstGroup(groupName, groupIndex); i==true;
			i=theConfig->GetNextGroup(groupName, groupIndex))
{

	if(wxFileExists(theConfig->Read(groupName+"/icon")))
	{
		wxImage img(theConfig->Read(groupName+"/icon"));
		if(img.Ok())
		{
			wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
			wxMemoryDC dc;
			dc.SelectObject(aBitmap);
			dc.SetBrush(*wxWHITE_BRUSH);

			dc.Clear();
			dc.DrawBitmap(wxBitmap(img.Rescale(ASTADEICONHIGHT,ASTADEICONHIGHT)),4,0,true);

			int idx = AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));
			myUserAppIcons[theConfig->Read(groupName+"/filetype")] = idx;
		}
	}
}

theConfig->SetPath("/");
