wxFileName aFileName = myModelElement->GetFileName();

wxArrayString retVal;

wxRegEx reTargets;

bool suc = reTargets.Compile("^([[:alpha:]]+)[:][^=]", wxRE_DEFAULT | wxRE_NEWLINE);
wxASSERT_MSG(suc, "RegExp to find make targets has errors!");

wxFile aFile(aFileName.GetFullPath().c_str());

if(aFile.IsOpened())
{
	wxString buffer;
	wxChar* buf = buffer.GetWriteBuf(aFile.Length());

	wxASSERT_MSG(buf!=NULL, "Could not get a write buffer for read makefile!");

	size_t cnt = aFile.Read(buf, aFile.Length());

	wxASSERT_MSG(cnt==aFile.Length(), "Makefile was not read completely!");

	buffer.UngetWriteBuf();

	size_t start;
	size_t len;
	while(reTargets.Matches(buffer))
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