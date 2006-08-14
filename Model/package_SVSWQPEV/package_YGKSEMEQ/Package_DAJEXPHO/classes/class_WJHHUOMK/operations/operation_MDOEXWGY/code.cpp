fprintf(implementationFile,"#include \"%s.h\"\n\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"// Include of event primitive defines\n");
fprintf(specificationFile,"#include %s\n\n",theStatechart.GetEventType().c_str());
fprintf(specificationFile,"// Include of VirtualStateMachine base class\n");
fprintf(specificationFile,"#include VirtualStateMachine.hpp\n\n");

fprintf(specificationFile,"class %s : public CVirtualStateMachine\n{\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"\tpublic:\n");
CodeTriggerIDs(theStatechart);
CodeConstructor(theStatechart);
CodeInitialize(theStatechart);
CodeTakeEvent(theStatechart);

AdeElementIterator it;

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
		CodeIsInStateFunction(theStatechart,*static_cast<AdeState*>(aElement));
	delete aElement;
}

fprintf(specificationFile,"\n\tprotected:\n");

CodeActions(theStatechart);
CodeGuards(theStatechart);

fprintf(specificationFile,"\n\tprivate:\n");

CodeNoState(theStatechart);
CodeState(theStatechart);
CodeEnterPointer(theStatechart);
CodeEnterFunction(theStatechart);

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(theStatechart,*aState);
		CodeEnterState(theStatechart,*aState);

/*
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
*/
	}
	delete aElement;
}

fprintf(specificationFile,"};\n");
