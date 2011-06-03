//~~ void UpdateUserAppIcons() [AstadeFile] ~~
/* rebuild cache from astade.ini */

wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->SetPath("/UserApps");

wxString groupName;
long groupIndex;

for (bool b = theConfig->GetFirstGroup(groupName, groupIndex); b;
			b = theConfig->GetNextGroup(groupName, groupIndex))
{

	if (wxFileExists(theConfig->Read(groupName + "/icon")))
	{
		wxImage img(theConfig->Read(groupName + "/icon"));
		if (img.Ok())
		{
			wxBitmap aBitmap(ASTADEICONWIDTH, ASTADEICONHEIGHT);
			wxMemoryDC dc;
			dc.SelectObject(aBitmap);
			dc.SetBrush(*wxWHITE_BRUSH);

			dc.Clear();
			dc.DrawBitmap(wxBitmap(img.Rescale(ASTADEICONHEIGHT, ASTADEICONHEIGHT)), 4, 0, true);

			AstadeIcons::Instance()->Add("user/" + theConfig->Read(groupName + "/filetype"), wxBitmap(aBitmap.ConvertToImage()));
		}
	}
}

theConfig->SetPath("/");
