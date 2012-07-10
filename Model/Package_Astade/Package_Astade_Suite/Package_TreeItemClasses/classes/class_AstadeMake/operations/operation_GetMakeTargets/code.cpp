//~~ wxArrayString GetMakeTargets() [AstadeMake] ~~

wxFileName aFileName(myModelElement->GetFileName());

wxArrayString retVal;

wxRegEx reTargets;

bool suc __attribute__((unused)); // don't warn if this is unused
suc = reTargets.Compile(wxS("^([[:alpha:]]+)[:]([^=]|$)"), wxRE_DEFAULT | wxRE_NEWLINE);
wxASSERT_MSG(suc, wxS("RegExp to find make targets has errors!"));

wxFile aFile(aFileName.GetFullPath());

if (aFile.IsOpened())
{
	char* buf = new char[aFile.Length()];
	wxASSERT_MSG(buf != NULL, wxS("Could not get a buffer to read makefile!"));

	ssize_t cnt __attribute__((unused)); // don't warn if this is unused
	cnt = aFile.Read(buf, aFile.Length());
	wxASSERT_MSG(cnt == aFile.Length(), wxS("Makefile was not read completely!"));

	wxString buffer(buf, wxConvAuto(), aFile.Length());
	delete [] buf;

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
	wxASSERT_MSG(0, wxS("Cannot open the makefile!"));
}

return retVal;
