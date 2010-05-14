wxDir aDir(aDirectory.GetPath());

if (!aDir.IsOpened())
	return;

wxString currentFilename;

if (aDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_DIRS))
	do
	{
		wxFileName aNewFileName(aDirectory);
		aNewFileName.AppendDir(currentFilename);
		aNewFileName.SetFullName(wxS("ModelNode.ini"));
		if (aNewFileName.FileExists())
			theFilenameList.push_back(aNewFileName);
		else
		{
			aNewFileName.SetFullName(wxS("index.html"));
			if (aNewFileName.FileExists())
				theFilenameList.push_back(aNewFileName);
		}
	} while (aDir.GetNext(&currentFilename));

if (aDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_FILES))
	do
	{
		if (currentFilename != wxS("ModelNode.ini"))
		{
			wxFileName aNewFileName(aDirectory);
			aNewFileName.SetFullName(currentFilename);
			theFilenameList.push_back(aNewFileName);
		}
	} while (aDir.GetNext(&currentFilename));
