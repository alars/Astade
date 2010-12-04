//~~ int GetIconIndex() [AstadeSourceFile] ~~

wxArrayString names;

names.Add("file");

wxFileName aName = myModelElement->GetFileName();

if (aName.GetExt() == "cpp")
	names.Add(CODE_CPlusPlus);
else if (aName.GetExt() == "h")
	names.Add("h");
else if (aName.GetExt() == "dox")
	names.Add("doxygen");
else if (aName.GetExt() == "c")
	names.Add(CODE_C);

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
	case AdeSearch::contain:
		names.Add("hasfound");
		break;
	case AdeSearch::found:
		names.Add("found");
		break;
	default:
		break;
	}
}

if (classOfFile.find(aName.GetFullPath()) != classOfFile.end())
{
	wxDateTime access,mod,create;
	aName.GetTimes(&access,&mod,&create);
	
	AdeModelElement* anElement = AdeModelElement::CreateNewElement(classOfFile[aName.GetFullPath()]);
	AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
	
	if (aName.GetExt() == aClass->GetSpecExtension())
	{
		if (aClass->GetModificationTime() < mod)
			names.Add("attention");
		else if (aClass->GetModificationTime() > mod)
			names.Add("changed");
		else 
			names.Add("belonging");
	}
	else if (aName.GetExt() == aClass->GetImpExtension())
	{
		if (aClass->GetCodeModificationTime() < mod)
			names.Add("attention");
		else if (aClass->GetCodeModificationTime() > mod)
			names.Add("changed");
		else 
			names.Add("belonging");
	}

	delete anElement;
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
