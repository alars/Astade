//~~ int GetIconIndex() [AstadeTransition] ~~

wxArrayString names;

wxFileConfig theConfig(wxEmptyString, wxEmptyString, wxEmptyString, myModelElement->GetFileName().GetFullPath());

wxString TransitionType = theConfig.Read(wxS("Astade/TransitionType"));

if (TransitionType == wxS("Self"))
	names.Add(wxS("selftransition"));
else if (TransitionType == wxS("Internal"))
	names.Add(wxS("internaltransition"));
else if (TransitionType == wxS("Terminate"))
	names.Add(wxS("terminate"));
else
	names.Add(wxS("transition"));

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
	if	(myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if	(myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
