fprintf(implementationFile,"\n{\n");
fprintf(implementationFile,"\tsm = sm;\n");
fprintf(implementationFile,"\tevt = evt;\n");

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	fprintf(implementationFile,"\t//Call Entry Action.\n");
	fprintf(implementationFile,"\t%s_impl_%s(sm, evt);\n", theStatechart.GetName().Lower().c_str(), EntryAction.Lower().c_str());
}

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	fprintf(implementationFile,"\t//Start Timer.\n");
	fprintf(implementationFile,"\t%s_COMMON_TMR_START(&(sm->tmr), %s);\n", theStatechart.GetName().Upper().c_str(), aTimeout.c_str());
}

fprintf(implementationFile,"\t//Set the new state.\n");
fprintf(implementationFile,"\t%s_COMMON_STATE_CHANGE_MSG(sm, %s);\n",theStatechart.GetName().Upper().c_str(), theState.GetName().Lower().c_str());
fprintf(implementationFile,"\tsm->the_state = %s_sm_s_%s;\n", theStatechart.GetName().Lower().c_str(), theState.GetName().Lower().c_str());


AdeElementIterator it;
for (it=theState.begin();it!=theState.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (!aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart,theState,*aTransition);
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
			CodeEventlessTransition(theStatechart,theState,*aTransition);
	}
	delete aElement;
}

fprintf(implementationFile,"\t\tsm->next_state = NULL; // We stay in this state\n");

fprintf(implementationFile,"}\n\n");