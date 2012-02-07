//~~ int GetIconIndex() [AstadeSourceFile] ~~

wxArrayString names;

names.Add(wxS("file"));

wxFileName aName = myModelElement->GetFileName();

if (aName.GetExt() == wxS("cpp"))
	names.Add(CODE_CPlusPlus);
else if (aName.GetExt() == wxS("h"))
	names.Add(wxS("h"));
else if (aName.GetExt() == wxS("dox"))
	names.Add(wxS("doxygen"));
else if (aName.GetExt() == wxS("c"))
	names.Add(CODE_C);

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
	case AdeSearch::contain:
		names.Add(wxS("hasfound"));
		break;
	case AdeSearch::found:
		names.Add(wxS("found"));
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
			names.Add(wxS("attention"));
		else if (aClass->GetModificationTime() > mod)
			names.Add(wxS("changed"));
		else 
			names.Add(wxS("belonging"));
	}
	else if (aName.GetExt() == aClass->GetImpExtension())
	{
		if (aClass->GetCodeModificationTime() < mod)
			names.Add(wxS("attention"));
		else if (aClass->GetCodeModificationTime() > mod)
			names.Add(wxS("changed"));
		else 
			names.Add(wxS("belonging"));
	}

	delete anElement;
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
