wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString entry;
long dummy;
std::list<wxFileName> ret;

theConfig.SetPath("/Components");
bool cont = theConfig.GetFirstEntry(entry, dummy);

while (cont)
{
	    entry.Replace("|", "/");
	    ret.push_back(wxFileName(entry));
	    cont = theConfig.GetNextEntry(entry, dummy);
}

return AdeElementIterator(ret);