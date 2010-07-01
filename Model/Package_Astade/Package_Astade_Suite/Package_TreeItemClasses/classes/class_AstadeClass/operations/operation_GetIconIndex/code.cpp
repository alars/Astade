//~~ int GetIconIndex() [AstadeClass] ~~
wxArrayString names;

names.Add("class");

wxFileName aName = static_cast<AdeClass*>(myModelElement)->GetImpFileName();
bool attentionSet = false;

if (aName.FileExists())
{
    wxDateTime access,mod,create;
    aName.GetTimes(&access,&mod,&create);
    if (mod > create)
    {
        names.Add("attention");
        attentionSet = true;
    }
}

if (static_cast<AdeClass*>(myModelElement)->IsManualClass())
	names.Add("manual");
else if (!static_cast<AdeClass*>(myModelElement)->IsLibClass())
    names.Add(static_cast<AdeClass*>(myModelElement)->codingLanguage());
	
if (!attentionSet)
{
	if (static_cast<AdeClass*>(myModelElement)->IsLibClass())
		names.Add("lib");
	else if (static_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
	{
		if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
			names.Add("belonging");
		else
			names.Add("changed");
	}
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

if (static_cast<AdeClass*>(myModelElement)->IsTraced())
    names.Add("traced");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
