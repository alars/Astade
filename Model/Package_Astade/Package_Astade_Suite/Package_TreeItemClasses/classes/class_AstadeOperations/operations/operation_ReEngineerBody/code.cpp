//~~ void ReEngineerBody(const wxFileName& parent) [AstadeOperations] ~~

AdeModelElement* anElement = AdeModelElement::CreateNewElement(parent);
AdeOperationBase* theOperation = dynamic_cast<AdeOperationBase*>(anElement);
if (theOperation)
{
	wxFileName codeFileName(theOperation->GetActionCodeFile());

	myOperationParser->body.Create(codeFileName.GetFullPath());
	myOperationParser->body.Write(wxTextFileType_Unix);
}
delete anElement;
