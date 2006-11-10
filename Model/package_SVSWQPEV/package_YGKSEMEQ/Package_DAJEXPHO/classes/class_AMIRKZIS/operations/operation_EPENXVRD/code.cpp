wxString event = theTransition.GetTrigger();

if ((event.empty()) && (!theTransition.IsInternalTransition()))
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile,"\t// %s\n",theTransition.GetLabel().c_str());

	if (guard.empty())
		fprintf(implementationFile,"\tif (true)\n\t{\n");
	else
		fprintf(implementationFile,"\tif (%s(theEvent))\n\t{\n",theTransition.GetGuard().c_str());

	std::set<wxString> aSet = theTransition.GetActions();

	if (!aSet.empty())
		fprintf(implementationFile,"\t\t// Actions\n");

	for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
		fprintf(implementationFile,"\t\t%s(theEvent);\n",(*iter).c_str());

	wxString nextState = theTransition.GetDestination();

	if (!theState.GetExitAction().empty())
	{
		fprintf(implementationFile,"\t\t// exit action\n");
		fprintf(implementationFile,"\t\t%s(theEvent);\n",theState.GetExitAction().c_str());
	}
	fprintf(implementationFile,"\t\t// next state\n");
	fprintf(implementationFile,"\t\tnextState = &%s::Enter_%s;\n",theStatechart.GetName().c_str(),nextState.c_str());

	fprintf(implementationFile,"\t}\n\telse\n");
}
