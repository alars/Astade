wxTextDataObject aText;
wxClipboard aClipboard;
bool success;

delete myOperationParser;
myOperationParser = 0;

if (aClipboard.Open())
{
	success = aClipboard.GetData(aText);
	aClipboard.Close();
}

if (!success)
	return false;

myOperationParser = new OperationParser(aText.GetText());

return myOperationParser->ParseSuccessful();