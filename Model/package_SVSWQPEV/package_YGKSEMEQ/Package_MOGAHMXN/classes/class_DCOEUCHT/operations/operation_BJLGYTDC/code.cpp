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

	if(reTargets.Matches(buffer))
		for(size_t i = 1; i<reTargets.GetMatchCount(); i++)
		{
			retVal.Add(reTargets.GetMatch(buffer, i));
		}
	
}
else
{
	wxASSERT_MSG(0, "Can not open the makefile!");
}

return retVal;