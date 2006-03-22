wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/HtmlBrowser"));

const wxString& dir = wxFileSelector("Set HTML Browser",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
	htmlBrowserPathTextControl->SetValue(filename.GetFullPath());