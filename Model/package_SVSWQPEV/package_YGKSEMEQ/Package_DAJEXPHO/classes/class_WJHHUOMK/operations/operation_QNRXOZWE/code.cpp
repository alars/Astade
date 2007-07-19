fprintf(specificationFile, "\t\t//! \\brief This is the state function for state %s.\n", (const char*)theState.GetName().c_str());
fprintf(specificationFile, "\t\tvoid %s(CMessage& message);\n\n", (const char*)theState.GetName().c_str());

fprintf(implementationFile, "void %s::%s(CMessage& message)\n{\n", (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str());

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

fprintf(implementationFile, "\t{\n\t\t// not handled\n\t\tmessage.NotHandeled();\n\t}\n\tEnterState(message);\n}\n\n");
