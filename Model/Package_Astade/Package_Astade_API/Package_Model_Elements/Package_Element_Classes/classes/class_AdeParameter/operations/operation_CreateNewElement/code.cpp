wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, wxS("parameter"), ITEM_IS_PARAMETER, true);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

AdeElementIterator it(aFileName);
AdeElementIterator end;

int count = 0;
while (it != end)
{
	AdeModelElement* anElement = it.CreateNewElement();
	int tmp = anElement->GetType() & 0xff;
	if (tmp > count)
		count = tmp;
	delete anElement;
	++it;
}

count++;
count &= 0xff;

theConfig.Write(wxS("Astade/Name"), parameterName);
theConfig.Write(wxS("Astade/Type"), ITEM_IS_PARAMETER + count);
theConfig.Write(wxS("Astade/CodingType"), codingType);
theConfig.Write(wxS("Astade/Default"), defaultValue);

return aFileName;
