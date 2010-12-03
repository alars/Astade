//~~ int GetIconIndex() [AstadeClass] ~~

wxArrayString names;
names.Add(wxS("class"));

AdeClass* theClass = dynamic_cast<AdeClass*>(myModelElement);
wxFileName aName = theClass->GetImpFileName();

wxDateTime impGeneration    = theClass->GetImpGenerationTime();
wxDateTime codeModification = theClass->GetCodeModificationTime();

bool attentionSet = false;

if (impGeneration > codeModification)
{
	names.Add(wxS("attention"));
	attentionSet = true;
}

if (theClass->IsManualClass())
	names.Add(wxS("manual"));
else if (!theClass->IsLibClass())
    names.Add(theClass->codingLanguage());
	
if (!attentionSet)
{
	if (theClass->IsLibClass())
		names.Add(wxS("lib"));
	else if (theClass->IsInActiveComponent())
	{
		if (impGeneration >= codeModification)
			names.Add(wxS("belonging"));
		else
			names.Add(wxS("changed"));
	}
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
	if(myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if(myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

if (theClass->IsTraced())
    names.Add(wxS("traced"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
