wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile, "\t// %s\n", (const char*)theTransition.GetLabel().c_str());

	if (guard.empty())
		fprintf(implementationFile, "\tif (message.Primitive() == %s)\n\t{\n", (const char*)event.c_str());
	else
		fprintf(implementationFile, "\tif ((message.Primitive() == %s) && (%s(message)))\n\t{\n", (const char*)event.c_str(), (const char*)theTransition.GetGuard().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	wxString nextState = theTransition.GetDestination();

	if (!theTransition.IsInternalTransition())
	{
		if (!theState.GetExitAction().empty())
		{
			fprintf(implementationFile, "\t\t// exit action\n");
			fprintf(implementationFile, "\t\t%s(message);\n", (const char*)theState.GetExitAction().c_str());
		}

		if (!theState.GetTimeout().empty())
		{
			fprintf(implementationFile, "\t\t// Stop Timer\n");
			fprintf(implementationFile, "\t\tif ((message.Primitive() != dIID_VFSM_MSG_AbbruchTimer) && (m_RunningTimer))\n\t\t\tCMessage::Delete(m_RunningTimer);\n");
			fprintf(implementationFile, "\t\tm_RunningTimer = 0;\n\n");
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

	for (std::list<wxString>::iterator iter = aList.begin(); iter!=aList.end(); iter++)
		fprintf(implementationFile, "\t\t%s(message);\n", (const char*)(*iter).c_str());

	fprintf(implementationFile, "\t}\n\telse\n");
}
