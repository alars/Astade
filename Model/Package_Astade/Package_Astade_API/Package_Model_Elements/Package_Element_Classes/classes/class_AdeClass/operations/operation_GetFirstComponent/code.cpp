wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString entry;
long dummy;
std::list<wxFileName> ret;

theConfig.SetPath(wxS("/Components"));
bool cont = theConfig.GetFirstEntry(entry, dummy);

while (cont)
{
	    ret.push_back(AdeGUIDCache::Instance()->GetCachedEntry(entry));
	    cont = theConfig.GetNextEntry(entry, dummy);
}

return AdeElementIterator(ret);
