//~~ void CodeEnterState(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~

fprintf(implementationFile, "\n{\n");
fprintf(implementationFile, "\tsm = sm;\n");
fprintf(implementationFile, "\tevt = evt;\n");

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	fprintf(implementationFile, "\t//Call Entry Action.\n");
	fprintf(implementationFile, "\t%s_impl_%s(sm, evt);\n", (const char*)theStatechart.GetName().Lower().utf8_str(), (const char*)EntryAction.Lower().utf8_str());
}

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	fprintf(implementationFile, "\t//Start Timer.\n");
	fprintf(implementationFile, "\t%s_COMMON_TMR_START(sm, %s);\n", (const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)aTimeout.utf8_str());
}

fprintf(implementationFile, "\t//Set the new state.\n");
fprintf(implementationFile, "\t%s_COMMON_STATE_CHANGE_MSG(sm, %s);\n", (const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)theState.GetName().Lower().utf8_str());
fprintf(implementationFile, "\tsm->the_state = %s_sm_s_%s;\n", (const char*)theStatechart.GetName().Lower().utf8_str(), (const char*)theState.GetName().Lower().utf8_str());


AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(anElement);
		if (!aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart, theState, *aTransition);
	}
	delete anElement;
}

for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(anElement);
		if (aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart, theState, *aTransition);
	}
	delete anElement;
}

fprintf(implementationFile, "\t\tsm->next_state = NULL; // We stay in this state\n");

fprintf(implementationFile, "}\n\n");
