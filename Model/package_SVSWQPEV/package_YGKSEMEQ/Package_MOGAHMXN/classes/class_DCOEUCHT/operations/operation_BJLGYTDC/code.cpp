wxFileName aFileName(myModelElement->GetFileName());

wxArrayString retVal;

wxRegEx reTargets;

bool suc = reTargets.Compile("^([[:alpha:]]+)[:][^=]", wxRE_DEFAULT | wxRE_NEWLINE);
wxASSERT_MSG(suc, "RegExp to find make targets has errors!");

wxFile aFile(aFileName.GetFullPath());

if (aFile.IsOpened())
{
	char* buf = new char[aFile.Length()];
	wxASSERT_MSG(buf != NULL, "Could not get a buffer to read makefile!");

	size_t cnt = aFile.Read(buf, aFile.Length());
	wxASSERT_MSG(cnt == aFile.Length(), "Makefile was not read completely!");

	wxString buffer(buf, aFile.Length());
	delete buf;

	size_t start;
	size_t len;
	while (reTargets.Matches(buffer))
	{
		reTargets.GetMatch(&start, &len, 1);
		retVal.Add(buffer.Mid(start, len));
		buffer.Remove(start, len);
	}

}
else
{
	wxASSERT_MSG(0, "Can not open the makefile!");
}

return retVal;
