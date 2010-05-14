wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString entry;
long dummy;
std::list<wxFileName> ret;

theConfig.SetPath(wxS("/Components"));
bool cont = theConfig.GetFirstEntry(entry,dummy);

while (cont)
{
	    wxFileName aFileName = AdeGUIDCache::Instance()->GetCachedEntry(entry);
	    if (!aFileName.FileExists())
	    {	// remove from belonging list
	    	theConfig.DeleteEntry(entry);
	    	theConfig.Flush();
	    	return(GetFirstComponent());
	    }
	    ret.push_back(AdeGUIDCache::Instance()->GetCachedEntry(entry));
	    cont = theConfig.GetNextEntry(entry,dummy);
}

return AdeElementIterator(ret);
