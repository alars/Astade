alreadyTerminated = true;
exitCode = status;

wxConfigBase* theConfig = wxConfigBase::Get();
wxString theSoundFile(theConfig->Read("TreeView/BuildSound", wxEmptyString));

if (!theSoundFile.empty())
{
	theSound.Create(theSoundFile);
	theSound.Play();
}
