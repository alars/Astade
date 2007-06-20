wxString event = theTransition.GetTrigger();

if ((event.empty()) && (!theTransition.IsInternalTransition()))
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile,"\t// %s\n",theTransition.GetLabel().c_str());
	fprintf(implementationFile,"\t/* %s */\n", theTransition.GetDescription().c_str());

	if (guard.empty())
		fprintf(implementationFile,"\tif (TRUE)\n\t{\n");
	else
		fprintf(implementationFile,"\tif (%s_impl_%s(sm, evt))\n\t{\n", 
			theStatechart.GetName().Lower().c_str(), theTransition.GetGuard().Lower().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	if (!aList.empty())
		fprintf(implementationFile,"\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter!=aList.end(); iter++)
		fprintf(implementationFile,"\t\t%s_impl_%s(sm, evt);\n", 
			theStatechart.GetName().Lower().c_str(), (*iter).Lower().c_str());

	wxString nextState = theTransition.GetDestination();

	if (!theState.GetExitAction().empty())
	{
		fprintf(implementationFile,"\t\t// exit action\n");
		fprintf(implementationFile,"\t\t%s_impl_%s(sm, evt);\n", 
			theStatechart.GetName().Lower().c_str(), theState.GetExitAction().Lower().c_str());
	}
	fprintf(implementationFile,"\t\t// next state\n");
	fprintf(implementationFile,"\t\tsm->next_state = %s_sm_enter_%s;\n",
		theStatechart.GetName().Lower().c_str(), nextState.Lower().c_str());

	fprintf(implementationFile,"\t}\n\telse\n");
}
