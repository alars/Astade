wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile,"\t// %s\n", theTransition.GetLabel().c_str());
	fprintf(implementationFile,"\t/* %s */\n", theTransition.GetDescription().c_str());

	if (guard.empty())
		fprintf(implementationFile,"\tif (%s_COMMON_IS_EVT(evt, %s))\n\t{\n", 
			theStatechart.GetName().Upper().c_str(), event.c_str());
	else
		fprintf(implementationFile,"\tif ((%s_COMMON_IS_EVT(evt, %s)) && (%s_impl_%s(sm, evt)))\n\t{\n", 
			theStatechart.GetName().Upper().c_str(), event.c_str(), 
			theStatechart.GetName().Lower().c_str(), theTransition.GetGuard().Lower().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	wxString nextState = theTransition.GetDestination();

	if (!theTransition.IsInternalTransition())
	{
		if (!theState.GetExitAction().empty())
		{
			fprintf(implementationFile,"\t\t// exit action\n");
			fprintf(implementationFile,"\t\t%s_impl_%s(sm, evt);\n",
				theStatechart.GetName().Lower().c_str(), theState.GetExitAction().Lower().c_str());
		}
		if (!theState.GetTimeout().empty())
		{
			fprintf(implementationFile,"\t\t// Stop Timer\n");
			fprintf(implementationFile,"\t\t%s_COMMON_TMR_STOP(&(sm->tmr));\n", theStatechart.GetName().Upper().c_str());
		}
		fprintf(implementationFile,"\t\t// next state\n");

		if (theTransition.IsSelfTransition())
			fprintf(implementationFile,"\t\tsm->next_state = %s_sm_enter_%s;\n",
				theStatechart.GetName().Lower().c_str(), theState.GetName().Lower().c_str());
		else
			fprintf(implementationFile,"\t\tsm->next_state = %s_sm_enter_%s;\n",
				theStatechart.GetName().Lower().c_str(), nextState.Lower().c_str());
	}
	else
		fprintf(implementationFile,"\t\t// internal Transition\n");

	if (!aList.empty())
		fprintf(implementationFile,"\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter!=aList.end(); iter++)
		fprintf(implementationFile,"\t\t%s_impl_%s(sm, evt);\n",
			theStatechart.GetName().Lower().c_str(), (*iter).Lower().c_str());

	fprintf(implementationFile,"\t\treturn TRUE;\n");
	fprintf(implementationFile,"\t}\n\telse\n");
}
