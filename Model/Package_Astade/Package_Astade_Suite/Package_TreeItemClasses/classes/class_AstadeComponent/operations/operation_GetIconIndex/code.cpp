//~~ int GetIconIndex() [AstadeComponent] ~~
wxArrayString names;

names.Add("component");

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
		sorceFileName.AppendDir("auto");
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
		sorceFileName.AppendDir("auto");
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

	if(isManuallyChanged)
		names.Add("attention");
	else if(isChanged)
		names.Add("changed");
	else
		names.Add("belonging");
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain: names.Add("hasfound");break;
		case AdeSearch::found: names.Add("found");break;
		default: break;
	}
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
