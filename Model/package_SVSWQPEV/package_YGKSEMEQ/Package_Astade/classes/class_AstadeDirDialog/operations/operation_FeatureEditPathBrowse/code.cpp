wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/FeatureEdit"));

const wxString& dir = wxFileSelector("Set Feature editor",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	featureEditPathTextControl->SetValue(filename.GetFullPath());
}

