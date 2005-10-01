wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"parameter",ITEM_IS_PARAMETER,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

AdeElementIterator it(aFileName);
AdeElementIterator end;

int count=0;
while (it!=end)
{
	++it;
	++count;
}

theConfig.Write("Astade/Type", ITEM_IS_PARAMETER + count);
theConfig.Write("Astade/CodingType", "int");
