wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/StatechartViewPath"));

const wxString& dir = wxFileSelector("Set Statechart viewer Path",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	statechartPathTextControl->SetValue(filename.GetFullPath());
}

