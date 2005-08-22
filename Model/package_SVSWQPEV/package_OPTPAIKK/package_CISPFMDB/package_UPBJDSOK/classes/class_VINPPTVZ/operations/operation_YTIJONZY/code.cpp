if ( !myDir->IsOpened() )
{
	currentFilename = "";
	return *this;
}

if (scanDirs)
{
	if (myDir->GetNext(&currentFilename))
	{
		return *this;
	}

	scanDirs = false;
	if ((myDir->GetFirst(&currentFilename,wxEmptyString,wxDIR_FILES))&&
		(currentFilename!="Desktop.ini"))
		return *this;
}


if ((myDir->GetNext(&currentFilename))&&
	(currentFilename!="Desktop.ini"))
	return *this;

if (myDir->GetNext(&currentFilename))
	return *this;

currentFilename = "";

return *this;