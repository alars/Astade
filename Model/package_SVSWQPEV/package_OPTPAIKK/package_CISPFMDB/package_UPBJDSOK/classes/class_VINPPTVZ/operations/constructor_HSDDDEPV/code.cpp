wxDir aDir(aFileName);

if ( !aDir.IsOpened() )
	return;

wxString currentFilename;

if (aDir.GetFirst(&currentFilename,wxEmptyString,wxDIR_DIRS))
do
{
	wxFileName aNewFileName(aFileName);
	aNewFileName.AppendDir(currentFilename);
	aNewFileName.SetFullName("Desktop.ini");
	theFilenameList.push_back(aNewFileName);
} while (aDir.GetNext(&currentFilename));

if (aDir.GetFirst(&currentFilename,wxEmptyString,wxDIR_FILES))
do
{
	if (currentFilename!="Desktop.ini")
	{
		wxFileName aNewFileName(aFileName);
		aNewFileName.SetFullName(currentFilename);
		theFilenameList.push_back(aNewFileName);
	}
} while (aDir.GetNext(&currentFilename));
