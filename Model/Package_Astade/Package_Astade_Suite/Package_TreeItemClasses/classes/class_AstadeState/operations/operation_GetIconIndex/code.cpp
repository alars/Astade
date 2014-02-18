//~~ int GetIconIndex() [AstadeState] ~~

wxArrayString names;

AdeState* theState = dynamic_cast<AdeState*>(myModelElement);
if (theState && theState->isIf())
    names.Add(wxS("if"));
else
    names.Add(wxS("state"));

if (search->isSet(AdeSearch::SearchIsActive))
{
    switch (myModelElement->Search(*search))
    {
        case AdeSearch::contain: names.Add(wxS("hasfound"));break;
        case AdeSearch::found: names.Add(wxS("found"));break;
        default: break;
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
