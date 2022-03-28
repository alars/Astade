//~~ void SaveDrawIo() [glFrame] ~~

wxFileName aFile(currentFile);

if (!aFile.IsOk() || aFile.IsDir())
{
	SaveAsDrawIo();
	return;
}

graphicPanel->SaveDrawIo(aFile.GetFullPath());

isChanged = false;
SetTitle(currentFile);
