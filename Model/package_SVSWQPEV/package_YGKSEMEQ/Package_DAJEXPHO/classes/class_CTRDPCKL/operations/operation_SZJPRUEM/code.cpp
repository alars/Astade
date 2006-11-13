AdeElementIterator it;

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		fprintf(specificationFile,"\t\t//! \\brief This checks, wether the machine is in state \"%s\".\n",static_cast<AdeState*>(aElement)->GetName().c_str());
		fprintf(specificationFile,"\t\t//! \\return true if is in state %s, false otherwise.\n",static_cast<AdeState*>(aElement)->GetName().c_str());
		fprintf(specificationFile,"\t\tbool IsIn%s();\n\n",static_cast<AdeState*>(aElement)->GetName().c_str());

		fprintf(implementationFile,"bool %s::IsIn%s()\n{\n\treturn (myImplementation->theState == ImpOf_%s::stateID_%s);\n}\n\n",theStatechart.GetName().c_str(), static_cast<AdeState*>(aElement)->GetName().c_str(),theStatechart.GetName().c_str(),static_cast<AdeState*>(aElement)->GetName().c_str());
	}
	delete aElement;
}





