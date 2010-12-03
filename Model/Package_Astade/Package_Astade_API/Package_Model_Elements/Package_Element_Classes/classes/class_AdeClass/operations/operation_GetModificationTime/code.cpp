//~~ wxDateTime GetModificationTime() [AdeClass] ~~

wxDateTime lastModified = wxDateTime(static_cast<time_t>(0));

wxString currentFilename;
wxFileName dirName(myFileName);

wxDir myDir(dirName.GetPath());

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

if (!HasOperations())
	return lastModified;

dirName.AppendDir(wxS("operations"));
dirName.SetFullName(wxEmptyString);

wxDir aDir(dirName.GetPath());

if (dirName.DirExists() && aDir.GetFirst(&currentFilename, wxEmptyString, wxDIR_DIRS))
	do
	{
		wxFileName anOperation(dirName);
		anOperation.SetFullName(wxS("ModelNode.ini"));
		anOperation.AppendDir(currentFilename);
		if (anOperation.FileExists())
		{
			AdeModelElement* anElement = AdeModelElement::CreateNewElement(anOperation);
			AdeOperationBase* theOperation = dynamic_cast<AdeOperationBase*>(anElement);
			if (theOperation)
			{
				wxDateTime aModified = theOperation->GetActionCodeFile().GetModificationTime();
				if (aModified > lastModified)
					lastModified = aModified;
			}
			delete anElement;
		}
	} while (aDir.GetNext(&currentFilename));

return lastModified;
