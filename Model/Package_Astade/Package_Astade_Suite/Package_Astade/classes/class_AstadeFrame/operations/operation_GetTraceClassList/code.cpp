//~~ wxString GetTraceClassList() [AstadeFrame] ~~

wxConfigBase* aConfig = wxConfigBase::Get();

aConfig->SetPath(wxS("/TreeView/TraceClasses"));

wxString entry;
long dummy;
wxString ret;

bool cont = aConfig->GetFirstEntry(entry, dummy);

while (cont)
{
	wxFileName aFile = AdeGUIDCache::Instance()->GetCachedEntry(entry);
	AdeModelElement* anElement = AdeModelElement::CreateNewElement(aFile);
	ret = ret + anElement->GetName() + wxS(" ");
    cont = aConfig->GetNextEntry(entry, dummy);
    delete anElement;
}

aConfig->SetPath(wxS("/"));

return ret;
