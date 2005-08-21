myDir = new wxDir(aFileName);
if ( !myDir->IsOpened() )
	return;

if (myDir->GetFirst(&currentFilename,wxEmptyString,wxDIR_DIRS))
	return;

scanDirs = false;

if ((myDir->GetFirst(&currentFilename,wxEmptyString,wxDIR_FILES))&&
	(currentFilename!="Desktop.ini"))
	return;

if (myDir->GetNext(&currentFilename))
	return;

currentFilename = "";
