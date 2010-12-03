//~~ void ReEngineerBody(const wxFileName& parent) [AstadeOperations] ~~

AdeClass* theClass = dynamic_cast<AdeClass*>(myModelElement->GetParent());
wxFileName codeFileName(parent);
codeFileName.SetFullName("code.cpp");

if (theClass)
	codeFileName.SetExt(theClass->GetImpExtension());
delete theClass;

myOperationParser->body.Create(codeFileName.GetFullPath());
myOperationParser->body.Write(wxTextFileType_Unix);
