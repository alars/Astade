printf("digraph G {\n");
printf("\tnode [style=filled, fontname=arial, fontsize=12, fillcolor=yellow, color=darkviolet]\n");

printf("\tNOSTATE [shape=circle label=\"\" width=0.2 style=filled fillcolor=black color=black];\n");

printf("\t%s [label=\"%s\", shape=Mrecord];\n","Test1","Test1");
printf("\t%s [label=\"%s\", shape=Mrecord];\n","Test2","{Test2 | n12345\\nhjgjh gjhg}");

printf("\tNOSTATE->Test1\n");
printf("\tTest2->Test1\n");


AdeElementIterator it;

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		printf("\t%s [label=\"{%s}\", shape=Mrecord];\n",aState->GetName().c_str(),aState->GetNodeLabel().c_str());
	}
	delete aElement;
}

printf("}\n");
