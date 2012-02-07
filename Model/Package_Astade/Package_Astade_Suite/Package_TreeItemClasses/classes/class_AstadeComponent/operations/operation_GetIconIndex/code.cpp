//~~ int GetIconIndex() [AstadeComponent] ~~

wxArrayString names;

names.Add(wxS("component"));

if (static_cast<AdeComponent*>(myModelElement)->IsActiveComponent())
{
	bool isChanged = false;
	bool isManuallyChanged = false;

	AstadeSourceFile::classOfFile.clear();

	AdeElementIterator it;
	for (it = static_cast<AdeComponent*>(myModelElement)->GetFirstBelongingClass(); it != static_cast<AdeComponent*>(myModelElement)->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		isChanged |= (aClass && (aClass->GetCodeModificationTime() > aClass->GetImpGenerationTime()));
		isManuallyChanged |= (aClass && (aClass->GetCodeModificationTime() < aClass->GetImpGenerationTime()));

		wxFileName sorceFileName(myModelElement->GetFileName());
		sorceFileName.AppendDir(wxS("auto"));
		sorceFileName.SetName(aClass->GetName());

		if (!aClass->GetImpExtension().empty())
		{
			sorceFileName.SetExt(aClass->GetImpExtension());
			AstadeSourceFile::classOfFile[sorceFileName.GetFullPath()] = aClass->GetFileName();
		}

		if (!aClass->GetSpecExtension().empty())
		{
			sorceFileName.SetExt(aClass->GetSpecExtension());
			AstadeSourceFile::classOfFile[sorceFileName.GetFullPath()] = aClass->GetFileName();
		}

		delete anElement;
	}

	for (it = static_cast<AdeComponent*>(myModelElement)->GetFirstBelongingStatechart(); it != static_cast<AdeComponent*>(myModelElement)->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		isChanged |= (aClass && (aClass->GetCodeModificationTime() > aClass->GetImpGenerationTime()));
		isManuallyChanged |= (aClass && (aClass->GetCodeModificationTime() < aClass->GetImpGenerationTime()));

		wxFileName sorceFileName(myModelElement->GetFileName());
		sorceFileName.AppendDir(wxS("auto"));
		sorceFileName.SetName(aClass->GetName());

		if (!aClass->GetImpExtension().empty())
		{
			sorceFileName.SetExt(aClass->GetImpExtension());
			AstadeSourceFile::classOfFile[sorceFileName.GetFullPath()] = aClass->GetFileName();
		}

		if (!aClass->GetSpecExtension().empty())
		{
			sorceFileName.SetExt(aClass->GetSpecExtension());
			AstadeSourceFile::classOfFile[sorceFileName.GetFullPath()] = aClass->GetFileName();
		}

		delete anElement;
	}

	if (isManuallyChanged)
		names.Add(wxS("attention"));
	else if (isChanged)
		names.Add(wxS("changed"));
	else
		names.Add(wxS("belonging"));
}

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
else
{
	if (myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
