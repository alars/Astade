//~~ bool ParseClipboard() [AstadeOperations] ~~

wxTextDataObject aText;
bool success = false;

delete myOperationParser;
myOperationParser = 0;

if (wxTheClipboard->Open())
{
	success = wxTheClipboard->GetData(aText);
	wxTheClipboard->Close();
}

if (!success)
	return false;

myOperationParser = new OperationParser(aText.GetText());

return myOperationParser->ParseSuccessful();
