wxString description(theState.GetDescription());
if (!description.empty())
    fprintf(specificationFile,"/*!\n%s\n*/\n",description.c_str());
else
    fprintf(specificationFile, "\t\t//! \\brief This is the state function for state %s.\n", (const char*)theState.GetName().c_str());

fprintf(specificationFile, "\t\tbool %s(const %s& theEvent, eventIDs itsID);\n\n", (const char*)theState.GetName().c_str(), (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "bool %s::%s(const %s& theEvent, eventIDs itsID)\n{\n", (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str(), (const char*)theStatechart.GetEventType().c_str());

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (!aTransition->GetGuard().empty())
			CodeTransition(theStatechart, theState, *aTransition);
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
			CodeTransition(theStatechart, theState, *aTransition);
	}
	delete aElement;
}

fprintf(implementationFile, "\t// not handled\n\treturn false;\n}\n\n");
