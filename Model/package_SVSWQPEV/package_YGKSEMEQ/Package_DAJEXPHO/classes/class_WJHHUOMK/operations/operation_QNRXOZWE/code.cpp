fprintf(specificationFile,"\t\t//! \\brief This is the state function for state %s.\n",theState.GetName().c_str());
fprintf(specificationFile,"\t\tvoid %s(CMessage& message);\n\n",theState.GetName().c_str(),theStatechart.GetEventType().c_str());

fprintf(implementationFile,"void %s::%s(CMessage& message)\n{\n",theStatechart.GetName().c_str(),theState.GetName().c_str(),theStatechart.GetEventType().c_str());

AdeElementIterator it;
for (it=theState.begin();it!=theState.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (!aTransition->GetGuard().empty())
			CodeTransition(theStatechart,theState,*aTransition);
	}
	delete aElement;
}

for (it=theState.begin();it!=theState.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (aTransition->GetGuard().empty())
			CodeTransition(theStatechart,theState,*aTransition);
	}
	delete aElement;
}

fprintf(implementationFile,"\t{\n\t\t// not handled\n\t\tmessage.NotHandeled();\n\t}\n\tEnterState(message);\n}\n\n");