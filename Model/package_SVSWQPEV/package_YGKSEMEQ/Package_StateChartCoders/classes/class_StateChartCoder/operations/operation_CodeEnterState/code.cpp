fprintf(specificationFile, "\t\t//! \\brief This is the enter function for state %s.\n", (const char*)theState.GetName().c_str());
fprintf(specificationFile, "\t\tvoid Enter_%s(const %s& theEvent);\n\n", (const char*)theState.GetName().c_str(), (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "void %s::Enter_%s(const %s& theEvent)\n{\n", (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str(), (const char*)theStatechart.GetEventType().c_str());

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	fprintf(implementationFile, "\t//Call Entry Action.\n");
	fprintf(implementationFile, "\t%s(theEvent);\n", (const char*)EntryAction.c_str());
}

fprintf(implementationFile, "\t//Set the new state.\n");
fprintf(implementationFile, "\ttheState = &%s::%s;\n", (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str());

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (!aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart, theState, *aTransition);
	}
	delete aElement;
}

for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart, theState, *aTransition);
	}
	delete aElement;
}

fprintf(implementationFile, "\tnextState = 0; // We stay in this state\n");
fprintf(implementationFile, "}\n\n");
