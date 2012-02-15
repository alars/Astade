//~~ void CodeTransition(AdeStatechart& theStatechart, AdeState& theState, AdeTransition& theTransition) [StateChartCoderCdSys] ~~

wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile, "\t// %s\n", (const char*)theTransition.GetLabel().utf8_str());
	fprintf(implementationFile,"\t/* %s */\n", (const char*)theTransition.GetDescription().utf8_str());

	if (guard.empty())
		fprintf(implementationFile, (const char*)"\tif (%s_COMMON_IS_EVT(evt, %s))\n\t{\n",
			(const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)event.utf8_str());
	else
		fprintf(implementationFile, "\tif ((%s_COMMON_IS_EVT(evt, %s)) && (%s_impl_%s(sm, evt)))\n\t{\n",
			(const char*)theStatechart.GetName().Upper().utf8_str(),
			(const char*)event.utf8_str(),
			(const char*)theStatechart.GetName().Lower().utf8_str(),
			(const char*)theTransition.GetGuard().Lower().utf8_str());

	std::list<wxString> aList = theTransition.GetActions();

	wxString nextState = theTransition.GetDestination();

	if (!theTransition.IsInternalTransition())
	{
		if (!theState.GetExitAction().empty())
		{
			fprintf(implementationFile, "\t\t// exit action\n");
			fprintf(implementationFile, "\t\t%s_impl_%s(sm, evt);\n",
				(const char*)theStatechart.GetName().Lower().utf8_str(),
				(const char*)theState.GetExitAction().Lower().utf8_str());
		}
		if (!theState.GetTimeout().empty())
		{
			fprintf(implementationFile, "\t\t// Stop Timer\n");
			fprintf(implementationFile, "\t\t%s_COMMON_TMR_STOP(sm);\n", (const char*)theStatechart.GetName().Upper().utf8_str());
		}
		fprintf(implementationFile, "\t\t// next state\n");

		if (theTransition.IsSelfTransition())
			fprintf(implementationFile, "\t\tsm->next_state = %s_sm_enter_%s;\n",
				(const char*)theStatechart.GetName().Lower().utf8_str(),
				(const char*)theState.GetName().Lower().utf8_str());
		else
			fprintf(implementationFile, "\t\tsm->next_state = %s_sm_enter_%s;\n",
				(const char*)theStatechart.GetName().Lower().utf8_str(),
				(const char*)nextState.Lower().utf8_str());
	}
	else
		fprintf(implementationFile, "\t\t// internal Transition\n");

	if (!aList.empty())
		fprintf(implementationFile, "\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter!=aList.end(); iter++)
		fprintf(implementationFile, "\t\t%s_impl_%s(sm, evt);\n",
			(const char*)theStatechart.GetName().Lower().utf8_str(),
			(const char*)(*iter).Lower().utf8_str());

	fprintf(implementationFile, "\t\treturn TRUE;\n");
	fprintf(implementationFile, "\t}\n\telse\n");
}
