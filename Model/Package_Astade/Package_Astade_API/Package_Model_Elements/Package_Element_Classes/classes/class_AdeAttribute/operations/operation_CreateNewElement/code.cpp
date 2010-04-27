wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"attribute",ITEM_IS_ATTRIBUTE | ITEM_IS_PRIVATE,true);

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

theConfig.Write("Astade/Type", (ITEM_IS_ATTRIBUTE | ITEM_IS_PRIVATE) + count);
theConfig.Write("Astade/CodingType", "int");
theConfig.Write("Astade/Bits", wxEmptyString);
theConfig.Write("Astade/Static", "no");
theConfig.Write("Astade/Const", "no");

return aFileName;
