wxString description(theState.GetDescription());
if (!description.empty())
    fprintf(specificationFile, "/*!\n%s\n*/\n", (const char*)description.c_str());
else
    fprintf(specificationFile, "//! \\brief This is the state function for state %s.\n", (const char*)theState.GetName().c_str());

fprintf(specificationFile, "void %s_%s(%s* me, %s* theEvent);\n\n", 
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theState.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "void %s_%s(%s* me, %s* theEvent)\n{\n", 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theState.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());

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

fprintf(implementationFile, "\t\treturn;\n}\n\n");
