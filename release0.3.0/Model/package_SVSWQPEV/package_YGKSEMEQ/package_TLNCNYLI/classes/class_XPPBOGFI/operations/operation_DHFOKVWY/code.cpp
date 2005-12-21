wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/StatechartCoder"));

const wxString& dir = wxFileSelector("Set Statechart Coder",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	statechartCoderPathTextControl->SetValue(filename.GetFullPath());
}

theConfig->Write("Tools/StatechartCoder",statechartCoderPathTextControl->GetValue());