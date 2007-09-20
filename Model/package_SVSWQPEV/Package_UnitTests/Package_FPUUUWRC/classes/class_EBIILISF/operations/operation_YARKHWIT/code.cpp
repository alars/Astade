if (functionBody.size() < 2)
	return;

functionBody.Remove(0,1);
functionBody.RemoveLast();

wxArrayString anArray;

wxStringTokenizer tokens(functionBody,"\r\n",wxTOKEN_RET_EMPTY);

while (tokens.HasMoreTokens())
	anArray.Add(tokens.GetNextToken().Trim());

while (anArray.GetCount() && anArray[0].empty())
	anArray.RemoveAt(0);

while (anArray.GetCount() && anArray[anArray.GetCount()-1].empty())
	anArray.RemoveAt(anArray.GetCount()-1);

RemoveAstadeSpecials(anArray);

while (HasEqualBegin(anArray,9))
	RemoveFirst(anArray);

while (HasEqualBegin(anArray,' '))
	RemoveFirst(anArray);

functionBody = wxEmptyString;

for (unsigned int i = 0; i < anArray.GetCount(); i++)
	functionBody += anArray[i] + "\n";