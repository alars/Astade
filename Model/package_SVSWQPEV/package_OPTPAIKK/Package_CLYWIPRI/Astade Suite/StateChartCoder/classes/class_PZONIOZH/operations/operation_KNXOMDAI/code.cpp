fprintf(specificationFile,"\t\tenum states\n\t\t{\n");

fprintf(specificationFile,"\t\t\tID_noState,\n");

AdeElementIterator it;
for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
		fprintf(specificationFile,"\t\t\tstateID_%s,\n",static_cast<AdeState*>(aElement)->GetName().c_str());
	delete aElement;
}

fprintf(specificationFile,"\t\t\tID_Last\n");

fprintf(specificationFile,"\t\t};\n\n");