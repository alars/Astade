std::set<wxString> aSet = theStatechart.GetTrigger();

int evtCount=1;
for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
{
	wxString event = *iter;
	if (event.Left(4)=="EVT_" && event.Right(1)==")")
	{
		fprintf(implementationFile,"//This is the event handler for trigger %s\n",event.c_str());
		fprintf(implementationFile,"void ImpOf_%s::HandleEventNo%03d(wxEvent& theEvent)\n{\n",theStatechart.GetName().c_str(),evtCount);

		AdeElementIterator iter;
		for (iter=theStatechart.begin();iter!=theStatechart.end();++iter)
		{
			AdeModelElement* stateElement = iter.CreateNewElement();

			if ((stateElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
			{
				AdeState* theState = static_cast<AdeState*>(stateElement);

				AdeElementIterator it;
				for (it=theState->begin();it!=theState->end();++it)
				{
					AdeModelElement* aElement = it.CreateNewElement();
					if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
					{
						AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
						if ((aTransition->GetTrigger()==event) && (!aTransition->GetGuard().empty()))
							CodeTransition(theStatechart,*theState,*aTransition);
					}
					delete aElement;
				}

				for (it=theState->begin();it!=theState->end();++it)
				{
					AdeModelElement* aElement = it.CreateNewElement();
					if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
					{
						AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
						if ((aTransition->GetTrigger()==event) && (aTransition->GetGuard().empty()))
							CodeTransition(theStatechart,*theState,*aTransition);
					}
					delete aElement;
				}
			}
			delete stateElement;
		}

		fprintf(implementationFile,"\t\treturn;\n");
		fprintf(implementationFile,"}\n\n");

		fprintf(specificationFile,"\t\t//! \\brief This is the event handler for trigger %s\n",event.c_str());
		fprintf(specificationFile,"\t\tvoid HandleEventNo%03d(wxEvent& theEvent);\n\n",evtCount++);
	}
}

fprintf(specificationFile,"\n");