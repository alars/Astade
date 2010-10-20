//~~ AdeElementIterator GetFirstBelongingClass() [AdeComponent] ~~

wxFileName aFileName = GetFileName();
aFileName.RemoveLastDir();
aFileName.RemoveLastDir();
// now aFileName is the model path

wxString entry;
long index;
std::list<wxFileName> ret;

myConfig->SetPath(wxS("/Classes"));
bool cont = myConfig->GetFirstEntry(entry,index);

while (cont)
{
    entry.Replace(wxS("|"), wxS("/"));
    ret.push_back(wxFileName(aFileName.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR ) + entry));
    cont = myConfig->GetNextEntry(entry, index);
}
myConfig->SetPath(wxS("/"));

return AdeElementIterator(ret);
