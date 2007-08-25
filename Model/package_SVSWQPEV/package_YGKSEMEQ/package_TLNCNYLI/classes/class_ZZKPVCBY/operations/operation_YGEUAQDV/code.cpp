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
			aIcon.CopyFromBitmap(wxBitmap(img.Rescale(ASTADEICONWIDTH,ASTADEICONHIGHT)));
			int idx = AstadeIcons::Instance()->Add(aIcon);
			myUserAppIcons[theConfig->Read(groupName+"/filetype")] = idx;
		}
	}
}

theConfig->SetPath("/");
