printf("digraph G {\n");
printf("\tNOSTATE [shape=circle label=\"\" width=0.2 style=filled fillcolor=black color=black];\n");


printf("\tNOSTATE->%s [label=\"%s\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];\n",theStatechart.GetInitialState().c_str(),theStatechart.GetDiagramLabel().c_str());

AdeElementIterator it;

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		printf("\t%s [label=\"{%s}\", shape=Mrecord, color=darkviolet, fontname=arial, fontsize=12];\n",aState->GetName().c_str(),aState->GetDiagramLabel().c_str());

		AdeElementIterator it2;
		for (it2=aState->begin();it2!=aState->end();++it2)
		{
			AdeModelElement* aElement2 = it2.CreateNewElement();
			if ((aElement2->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
			{
				AdeTransition* aTransition = static_cast<AdeTransition*>(aElement2);
				if (aTransition->IsNormalTransition())
				{
					if (!aTransition->GetDestination().empty())
						printf("\t%s->%s [label=\"%s\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];\n",aState->GetName().c_str(),aTransition->GetDestination().c_str(),aTransition->GetDiagramLabel().c_str());
				}
				if (aTransition->IsSelfTransition())
				{
					printf("\t%s->%s [label=\"%s\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];\n",aState->GetName().c_str(),aState->GetName().c_str(),aTransition->GetDiagramLabel().c_str());
				}
			}
			delete aElement2;
		}

	}
	delete aElement;
}

printf("}\n");
