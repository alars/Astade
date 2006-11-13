wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile,"\t// %s\n",theTransition.GetLabel().c_str());

	if (event.Left(4)=="EVT_" && event.Right(1)==")")
	{
		event.Truncate(event.size()-1);
		event += ",NULL)";
	}

	if (guard.empty())
		fprintf(implementationFile,"\tif (theState == stateID_%s)\n\t{\n",theState.GetName().c_str());
	else
		fprintf(implementationFile,"\tif ((theState == stateID_%s) && (%s(theEvent)))\n\t{\n",theState.GetName().c_str(),theTransition.GetGuard().c_str());

	std::set<wxString> aSet = theTransition.GetActions();

	wxString nextState = theTransition.GetDestination();

	if (!theTransition.IsInternalTransition())
	{
		if (!theState.GetExitAction().empty())
		{
			fprintf(implementationFile,"\t\t// exit action\n");
			fprintf(implementationFile,"\t\t%s(theEvent);\n",theState.GetExitAction().c_str());
		}
		fprintf(implementationFile,"\t\t// next state\n");

		if (theTransition.IsSelfTransition())
			fprintf(implementationFile,"\t\tnextState = &ImpOf_%s::Enter_%s;\n",theStatechart.GetName().c_str(),theState.GetName().c_str());
		else
			fprintf(implementationFile,"\t\tnextState = &ImpOf_%s::Enter_%s;\n",theStatechart.GetName().c_str(),nextState.c_str());
	}
	else
		fprintf(implementationFile,"\t\t// internal Transition\n");

	if (!aSet.empty())
		fprintf(implementationFile,"\t\t// Actions\n");

	for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
		fprintf(implementationFile,"\t\tmyHandlers.%s(theEvent);\n",(*iter).c_str());

	fprintf(implementationFile,"\t\treturn;\n");
	fprintf(implementationFile,"\t}\n\telse\n");
}
