//~~ wxDateTime GetCodeModificationTime() [AdeClass] ~~

wxDateTime lastModified = GetModificationTime();

if (!HasOperations())
	return lastModified;

wxFileName dirName(myFileName);
dirName.AppendDir(wxS("operations"));
dirName.SetFullName(wxEmptyString);

wxDir aDir(dirName.GetPath());

wxString currentFilename;
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

return lastModified+wxTimeSpan::Second();
