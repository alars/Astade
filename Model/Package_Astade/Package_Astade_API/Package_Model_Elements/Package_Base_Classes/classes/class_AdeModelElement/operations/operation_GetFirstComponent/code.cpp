//~~ AdeElementIterator GetFirstComponent() [AdeModelElement] ~~

wxString entry;
long dummy;
std::list<wxFileName> ret;

myConfig->SetPath(wxS("/Components"));
bool cont = myConfig->GetFirstEntry(entry,dummy);

while (cont)
{
	    wxFileName aFileName = AdeGUIDCache::Instance()->GetCachedEntry(entry);
	    if (!aFileName.FileExists())
	    {	// remove from belonging list
	    	myConfig->DeleteEntry(entry);
	    	myConfig->Flush();
			myConfig->SetPath(wxS("/"));
	    	return(GetFirstComponent());
	    }
	    ret.push_back(AdeGUIDCache::Instance()->GetCachedEntry(entry));
	    cont = myConfig->GetNextEntry(entry,dummy);
}
myConfig->SetPath(wxS("/"));

return AdeElementIterator(ret);
