//~~ wxDateTime GetModificationTime() [AdeClass] ~~

wxDateTime lastModified = wxDateTime(static_cast<time_t>(0));

wxFileName dirName(myFileName);
wxDir myDir(dirName.GetPath());

wxString currentFilename;
if (myDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_FILES))
	do
	{
		wxFileName anOperation(dirName);
		anOperation.SetFullName(currentFilename);
		if (anOperation.FileExists())
		{
			wxDateTime aModified = anOperation.GetModificationTime();
			if (aModified > lastModified)
				lastModified = aModified;
		}
	} while (myDir.GetNext(&currentFilename));

return lastModified+wxTimeSpan::Second();
