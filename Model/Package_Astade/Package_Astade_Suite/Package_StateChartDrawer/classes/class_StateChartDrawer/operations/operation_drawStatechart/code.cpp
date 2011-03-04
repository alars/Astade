//~~ void drawStatechart(AdeStatechart& theStatechart, FILE* stream) [StateChartDrawer] ~~
fprintf(stream,"digraph G {\n");
fprintf(stream,"\tfontsize=10, labelloc = \"t\", labeljust = \"l\";\n");
fprintf(stream,"\tlabel = \"%s\n%s\";\n",theStatechart.GetName().c_str(), theStatechart.GetDescription().c_str());

fprintf(stream,"\tNOSTATE [shape=circle label=\"\" width=0.2 style=filled fillcolor=black color=black];\n");


fprintf(stream,"\tNOSTATE->%s [label=\"%s\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];\n", (const char*)theStatechart.GetInitialState().c_str(), (const char*)theStatechart.GetDiagramLabel().c_str());

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		fprintf(stream,"\t%s [label=\"{%s}\", shape=Mrecord, color=darkviolet, fontname=arial, fontsize=12];\n", (const char*)aState->GetName().c_str(), (const char*)aState->GetDiagramLabel().c_str());

		AdeElementIterator it2;
		for (it2 = aState->begin(); it2 != aState->end(); ++it2)
		{
			AdeModelElement* aElement2 = it2.CreateNewElement();
			if ((aElement2->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
			{
				AdeTransition* aTransition = static_cast<AdeTransition*>(aElement2);
				if (aTransition->IsNormalTransition())
				{
					if (!aTransition->GetDestination().empty())
						fprintf(stream,"\t%s->%s [label=\"%s\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];\n", (const char*)aState->GetName().c_str(), (const char*)aTransition->GetDestination().c_str(), (const char*)aTransition->GetDiagramLabel().c_str());
				}
				if (aTransition->IsSelfTransition())
				{
					fprintf(stream,"\t%s->%s [label=\"%s\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];\n", (const char*)aState->GetName().c_str(), (const char*)aState->GetName().c_str(), (const char*)aTransition->GetDiagramLabel().c_str());
				}
			}
			delete aElement2;
		}
	}
	delete aElement;
}

fprintf(stream,"}\n");
