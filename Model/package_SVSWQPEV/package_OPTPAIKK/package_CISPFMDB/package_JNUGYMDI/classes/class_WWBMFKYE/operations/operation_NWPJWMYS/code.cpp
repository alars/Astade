wxDateTime lastModified = wxDateTime(static_cast<time_t>(0));

wxString currentFilename;
wxFileName dirName(myFileName);

wxDir myDir(dirName.GetPath());

if (myDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_FILES))
	do
	{
		::wxYield();
		wxFileName aOperation(dirName);
		aOperation.SetFullName(currentFilename);
		if (aOperation.FileExists())
		{
			wxDateTime aModified = aOperation.GetModificationTime();
			if (aModified > lastModified)
				lastModified = aModified;
		}
	} while (myDir.GetNext(&currentFilename));


if (!HasOperations())
	return lastModified;

dirName.AppendDir("operations");
dirName.SetFullName(wxEmptyString);

wxDir aDir(dirName.GetPath());

if (dirName.DirExists() && aDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_DIRS))
	do
	{
		::wxYield();
		wxFileName aOperation(dirName);
		aOperation.SetFullName("code.cpp");
		aOperation.AppendDir(currentFilename);
		if (aOperation.FileExists())
		{
			wxDateTime aModified = aOperation.GetModificationTime();
			if (aModified > lastModified)
				lastModified = aModified;
		}
	} while (aDir.GetNext(&currentFilename));

return lastModified;
