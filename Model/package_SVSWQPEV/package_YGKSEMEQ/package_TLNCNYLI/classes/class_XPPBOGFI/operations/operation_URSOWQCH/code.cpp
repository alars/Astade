wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/UseCasesPath"));

const wxString& dir = wxFileSelector("Set use case diagram viewer Path",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	usecasePathTextControl->SetValue(filename.GetFullPath());
}