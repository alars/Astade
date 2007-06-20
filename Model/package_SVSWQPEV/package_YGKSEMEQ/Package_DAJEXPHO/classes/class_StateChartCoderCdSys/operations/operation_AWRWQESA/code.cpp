AdeElementIterator it;

fprintf(specificationFile, "/*!@brief List of states */\n");
fprintf(specificationFile, "typedef enum\t%s_sm_state_id\n", theStatechart.GetName().Lower().c_str());
fprintf(specificationFile, "{\n");

fprintf(implementationFile, "// This array is for the is in State Function \n");
fprintf(implementationFile, "static\t%s_SM_STATE\t_the_states[%s_SM_STATE_ID_LAST_ELEMENT] =\n", 
theStatechart.GetName().Upper().c_str(), theStatechart.GetName().Upper().c_str());
fprintf(implementationFile, "{\n");


for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
		CodeIsInStateDataElement(theStatechart,*static_cast<AdeState*>(aElement));
	delete aElement;
}

fprintf(implementationFile, "};\n\n");

fprintf(specificationFile, "\n");
fprintf(specificationFile, "\t%s_SM_STATE_ID_LAST_ELEMENT\n", theStatechart.GetName().Upper().c_str());
fprintf(specificationFile, "} %s_SM_STATE_ID;\n\n", theStatechart.GetName().Upper().c_str());

