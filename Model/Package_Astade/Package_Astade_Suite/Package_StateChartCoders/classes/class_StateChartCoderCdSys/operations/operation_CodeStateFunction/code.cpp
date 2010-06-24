//~~ void CodeStateFunction(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~
fprintf(implementationFile,"\n{\n");
fprintf(implementationFile,"\tsm = sm;\n");
fprintf(implementationFile,"\tevt = evt;\n");

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

fprintf(implementationFile,"\t// not handled\n\t\treturn FALSE;\n}\n\n");