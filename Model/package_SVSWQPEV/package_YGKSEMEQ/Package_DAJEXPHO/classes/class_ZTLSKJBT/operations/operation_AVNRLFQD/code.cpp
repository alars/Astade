fprintf(specificationFile,"\t\t//! \\brief This is the state function for state %s.\n",theState.GetName().c_str());
fprintf(specificationFile,"\t\tbool %s(const %s& theEvent, eventIDs itsID);\n\n",theState.GetName().c_str(),theStatechart.GetEventType().c_str());

fprintf(implementationFile,"bool %s::%s(const %s& theEvent, eventIDs itsID)\n{\n",theStatechart.GetName().c_str(),theState.GetName().c_str(),theStatechart.GetEventType().c_str());

fprintf(implementationFile,"\tbool ret = false;\n");

fprintf(implementationFile,"\tswitch(itsID)\n\t{\n");

AdeElementIterator it;
for (it=theState.begin();it!=theState.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		CodeTransition(theStatechart,theState,*aTransition);
	}
	delete aElement;
}

fprintf(implementationFile,"\t\tdefault:\n");
fprintf(implementationFile,"\t\tbreak;\n");

fprintf(implementationFile,"\t}\n");

fprintf(implementationFile,"\treturn ret;\n");

fprintf(implementationFile,"}\n\n");