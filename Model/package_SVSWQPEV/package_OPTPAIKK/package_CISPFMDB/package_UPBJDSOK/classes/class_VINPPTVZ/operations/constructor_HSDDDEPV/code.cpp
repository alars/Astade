wxDir aDir(aFileName.GetPath());

if ( !aDir.IsOpened() )
	return;

wxString currentFilename;

if (aDir.GetFirst(&currentFilename,wxEmptyString,wxDIR_DIRS))
do
{
	wxFileName aNewFileName(aFileName);
	aNewFileName.AppendDir(currentFilename);
	aNewFileName.SetFullName("ModelNode.ini");
	theFilenameList.push_back(aNewFileName);
} while (aDir.GetNext(&currentFilename));

if (aDir.GetFirst(&currentFilename,wxEmptyString,wxDIR_FILES))
do
{
	if (currentFilename!="ModelNode.ini")
	{
		wxFileName aNewFileName(aFileName);
		aNewFileName.SetFullName(currentFilename);
		theFilenameList.push_back(aNewFileName);
	}
} while (aDir.GetNext(&currentFilename));
