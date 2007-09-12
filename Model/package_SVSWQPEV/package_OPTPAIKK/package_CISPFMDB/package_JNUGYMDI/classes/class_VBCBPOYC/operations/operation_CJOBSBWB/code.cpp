wxString label = myConfig->Read("Astade/Name","<name unknown>");
wxString internals;

if (!myConfig->Read("Astade/Timeout").empty())
{
	if (!internals.empty())
		internals += "\\n";
	internals += "Timeout: ";
	internals += myConfig->Read("Astade/Timeout");
}

if (!myConfig->Read("Astade/EntryAction").empty())
{
	if (!internals.empty())
		internals += "\\n";
	internals += "Entry: ";
	internals += myConfig->Read("Astade/EntryAction");
}

if (!myConfig->Read("Astade/ExitAction").empty())
{
	if (!internals.empty())
		internals += "\\n";
	internals += "Exit: ";
	internals += myConfig->Read("Astade/ExitAction");
}

AdeElementIterator it;
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(aElement);
		if (aTransition->IsInternalTransition())
		{
			if (!internals.empty())
				internals += "\\n";
			internals += aTransition->GetLabel();
		}
	}
	delete aElement;
}

if (!internals.empty())
{
	label += " | ";
	label += internals;
}

return label;