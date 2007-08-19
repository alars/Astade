wxDateTime lastModified = AdeModelElement::GetModificationTime();

wxString currentFilename;
wxFileName dirName(myFileName);
dirName.AppendDir("operations");

wxDir aDir(dirName.GetPath());

if (aDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_DIRS))
	do
	{
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