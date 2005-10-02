wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/OmdViewPath"));

const wxString& dir = wxFileSelector("Set OMD viewer",theFileName.GetPath(),theFileName.GetFullName(),"","*.*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	omdPathTextControl.SetValue(filename.GetFullPath());
}

