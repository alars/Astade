wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxFileName aFileName = GetFileName();
aFileName.RemoveLastDir();
aFileName.RemoveLastDir();
// now aFileName is the model path

wxString entry;
long dummy;
std::list<wxFileName> ret;

theConfig.SetPath(wxS("/Statecharts"));
bool cont = theConfig.GetFirstEntry(entry,dummy);

while (cont)
{
	    entry.Replace(wxS("|"), wxS("/"));
	    ret.push_back(wxFileName(aFileName.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR ) + entry));
	    cont = theConfig.GetNextEntry(entry, dummy);
}

return AdeElementIterator(ret);
