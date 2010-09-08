//~~ void ReEngineerBody(const wxFileName& parent) [AstadeOperations] ~~
wxFileName codeFileName(parent);
codeFileName.SetFullName("code.cpp");

myOperationParser->body.Create(codeFileName.GetFullPath());
myOperationParser->body.Write(wxTextFileType_Unix);