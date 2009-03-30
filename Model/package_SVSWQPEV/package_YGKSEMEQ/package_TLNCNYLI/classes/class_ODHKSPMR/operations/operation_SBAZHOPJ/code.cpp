wxConfigBase* aConfig = wxConfigBase::Get();

aConfig->SetPath("/TreeView/TraceClasses");

wxString entry;
long dummy;
wxString ret;

bool cont = aConfig->GetFirstEntry(entry,dummy);

while (cont)
{
	wxFileName aFile = AdeGUIDCache::Instance()->GetCachedEntry(entry);
	AdeModelElement* aElement = AdeModelElement::CreateNewElement(aFile);
	ret = ret + aElement->GetLabel() + " ";
    cont = aConfig->GetNextEntry(entry,dummy);
    delete aElement;
}

aConfig->SetPath("/");

return ret;