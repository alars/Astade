wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile, "\t// %s\n", (const char*)theTransition.GetLabel().c_str());

	if (guard.empty())
		fprintf(implementationFile, "\tif (itsID == ID_%s)\n\t{\n", (const char*)event.c_str());
	else
		fprintf(implementationFile, "\tif (itsID == ID_%s && %s(theEvent))\n\t{\n", (const char*)event.c_str(), (const char*)theTransition.GetGuard().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	wxString nextState = theTransition.GetDestination();

	if (!theTransition.IsInternalTransition())
	{
		if (!theState.GetExitAction().empty())
		{
			fprintf(implementationFile, "\t\t// exit action\n");
			fprintf(implementationFile, "\t\t%s(theEvent);\n", (const char*)theState.GetExitAction().c_str());
		}
		fprintf(implementationFile, "\t\t// next state\n");

		if (theTransition.IsSelfTransition())
			fprintf(implementationFile, "\t\tnextState = &%s::Enter_%s;\n", (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str());
		else
			fprintf(implementationFile, "\t\tnextState = &%s::Enter_%s;\n", (const char*)theStatechart.GetName().c_str(), (const char*)nextState.c_str());
	}
	else
		fprintf(implementationFile, "\t\t// internal Transition\n");

	if (!aList.empty())
		fprintf(implementationFile, "\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end();  iter++)
		fprintf(implementationFile, "\t\t%s(theEvent);\n", (const char*)(*iter).c_str());

	fprintf(implementationFile, "\t\treturn true;\n");
	fprintf(implementationFile, "\t}\n\telse\n");
}
