//~~ AdeElementIterator GetFirstComponent() [AdeClass] ~~

wxString entry;
long index;
std::list<wxFileName> ret;

myConfig->SetPath(wxS("/Components"));
bool cont = myConfig->GetFirstEntry(entry, index);

while (cont)
{
	    ret.push_back(AdeGUIDCache::Instance()->GetCachedEntry(entry));
	    cont = myConfig->GetNextEntry(entry, index);
}
myConfig->SetPath(wxS("/"));

return AdeElementIterator(ret);
