alreadyTerminated = true;
exitCode = status;

wxConfigBase* theConfig = wxConfigBase::Get();
wxString theSoundFile;

if (theConfig->Read("TreeView/BuildSound",&theSoundFile,wxEmptyString))
{
	theSound.Create(theSoundFile);
	theSound.Play();
}