wxFileName aFile(currentFile);

if (aFile.GetExt() != "ucm")
{
	SaveFileAs(event);
	return;
}



isChanged = false;
SetTitle(currentFile);
