//~~ wxFileName CreateNewElement(wxFileName parentFolder) [AdeAttribute] ~~
wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, wxS("attribute"), ITEM_IS_ATTRIBUTE | ITEM_IS_PRIVATE, true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

AdeElementIterator it(aFileName);
AdeElementIterator end;

int count = 0;
while (it != end)
{
	AdeModelElement* anElement = it.CreateNewElement();
	int tmp = anElement->GetType() & 0xFF;
	if (tmp > count)
		count = tmp;
	delete anElement;
	++it;
}

count++;
count &= 0xff;

theConfig.Write(wxS("Astade/Type"), (ITEM_IS_ATTRIBUTE | ITEM_IS_PRIVATE) + count);
theConfig.Write(wxS("Astade/CodingType"), wxS("int"));
theConfig.Write(wxS("Astade/Bits"), wxEmptyString);
theConfig.Write(wxS("Astade/Static"), wxS("no"));
theConfig.Write(wxS("Astade/Const"), wxS("no"));

return aFileName;
