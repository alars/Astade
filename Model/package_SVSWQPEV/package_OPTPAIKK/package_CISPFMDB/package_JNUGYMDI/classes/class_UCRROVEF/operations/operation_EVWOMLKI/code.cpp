wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"parameter",ITEM_IS_PARAMETER,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

AdeElementIterator it(aFileName);
AdeElementIterator end;

int count=0;
while (it!=end)
{
	AdeModelElement* aElement = it.CreateNewElement();
	int tmp = 0xff & aElement->GetType();
	if (tmp>count)
		count = tmp;
	delete aElement;
	++it;
}

count++;
count &= 0xff;

theConfig.Write("Astade/Name",parameterName);
theConfig.Write("Astade/Type", ITEM_IS_PARAMETER + count);
theConfig.Write("Astade/CodingType", codingType);
theConfig.Write("Astade/Default", defaultValue);

return aFileName;