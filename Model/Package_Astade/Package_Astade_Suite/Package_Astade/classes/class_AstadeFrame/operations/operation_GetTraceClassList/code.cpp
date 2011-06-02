//~~ wxString GetTraceClassList() [AstadeFrame] ~~

wxConfigBase* aConfig = wxConfigBase::Get();

aConfig->SetPath("/TreeView/TraceClasses");

wxString entry;
long dummy;
wxString ret;

bool cont = aConfig->GetFirstEntry(entry,dummy);

while (cont)
{
	wxFileName aFile = AdeGUIDCache::Instance()->GetCachedEntry(entry);
	AdeModelElement* anElement = AdeModelElement::CreateNewElement(aFile);
	ret = ret + anElement->GetName() + " ";
    cont = aConfig->GetNextEntry(entry,dummy);
    delete anElement;
}

aConfig->SetPath("/");

return ret;
