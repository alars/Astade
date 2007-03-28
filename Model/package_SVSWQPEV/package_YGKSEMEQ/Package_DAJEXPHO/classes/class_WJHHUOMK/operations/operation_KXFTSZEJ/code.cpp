wxString event = theTransition.GetTrigger();

if ((event.empty()) && (!theTransition.IsInternalTransition()))
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile,"\t// %s\n",theTransition.GetLabel().c_str());

	if (guard.empty())
		fprintf(implementationFile,"\tif (true)\n\t{\n");
	else
		fprintf(implementationFile,"\tif (%s(message))\n\t{\n",theTransition.GetGuard().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	if (!aList.empty())
		fprintf(implementationFile,"\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter!=aList.end(); iter++)
		fprintf(implementationFile,"\t\t%s(message);\n",(*iter).c_str());

	wxString nextState = theTransition.GetDestination();

	if (!theState.GetExitAction().empty())
	{
		fprintf(implementationFile,"\t\t// exit action\n");
		fprintf(implementationFile,"\t\t%s(message);\n",theState.GetExitAction().c_str());
	}
	fprintf(implementationFile,"\t\t// next state\n");
	fprintf(implementationFile,"\t\tnextState = &%s::Enter_%s;\n",theStatechart.GetName().c_str(),nextState.c_str());

	fprintf(implementationFile,"\t}\n\telse\n");
}
