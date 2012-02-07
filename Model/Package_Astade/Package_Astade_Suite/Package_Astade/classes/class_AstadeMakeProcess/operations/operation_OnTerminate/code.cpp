//~~ void OnTerminate(int pid, int status) [AstadeMakeProcess] ~~

alreadyTerminated = true;
exitCode = status;

wxConfigBase* theConfig = wxConfigBase::Get();
wxString theSoundFile(theConfig->Read(wxS("TreeView/BuildSound"), wxEmptyString));

if (!theSoundFile.empty())
{
	theSound.Create(theSoundFile);
	theSound.Play();
}
