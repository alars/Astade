wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile, "\t// %s\n", (const char*)theTransition.GetLabel().c_str());
	fprintf(implementationFile,"\t/* %s */\n", (const char*)theTransition.GetDescription().c_str());

	if (guard.empty())
		fprintf(implementationFile, (const char*)"\tif (%s_COMMON_IS_EVT(evt, %s))\n\t{\n", 
			(const char*)theStatechart.GetName().Upper().c_str(), (const char*)event.c_str());
	else
		fprintf(implementationFile, "\tif ((%s_COMMON_IS_EVT(evt, %s)) && (%s_impl_%s(sm, evt)))\n\t{\n", 
			(const char*)theStatechart.GetName().Upper().c_str(),
			(const char*)event.c_str(), 
			(const char*)theStatechart.GetName().Lower().c_str(),
			(const char*)theTransition.GetGuard().Lower().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	wxString nextState = theTransition.GetDestination();

	if (!theTransition.IsInternalTransition())
	{
		if (!theState.GetExitAction().empty())
		{
			fprintf(implementationFile, "\t\t// exit action\n");
			fprintf(implementationFile, "\t\t%s_impl_%s(sm, evt);\n",
				(const char*)theStatechart.GetName().Lower().c_str(),
				(const char*)theState.GetExitAction().Lower().c_str());
		}
		if (!theState.GetTimeout().empty())
		{
			fprintf(implementationFile, "\t\t// Stop Timer\n");
			fprintf(implementationFile, "\t\t%s_COMMON_TMR_STOP(&(sm->tmr));\n", (const char*)theStatechart.GetName().Upper().c_str());
		}
		fprintf(implementationFile, "\t\t// next state\n");

		if (theTransition.IsSelfTransition())
			fprintf(implementationFile, "\t\tsm->next_state = %s_sm_enter_%s;\n",
				(const char*)theStatechart.GetName().Lower().c_str(),
				(const char*)theState.GetName().Lower().c_str());
		else
			fprintf(implementationFile, "\t\tsm->next_state = %s_sm_enter_%s;\n",
				(const char*)theStatechart.GetName().Lower().c_str(),
				(const char*)nextState.Lower().c_str());
	}
	else
		fprintf(implementationFile, "\t\t// internal Transition\n");

	if (!aList.empty())
		fprintf(implementationFile, "\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter!=aList.end(); iter++)
		fprintf(implementationFile, "\t\t%s_impl_%s(sm, evt);\n",
			(const char*)theStatechart.GetName().Lower().c_str(),
			(const char*)(*iter).Lower().c_str());

	fprintf(implementationFile, "\t\treturn TRUE;\n");
	fprintf(implementationFile, "\t}\n\telse\n");
}
