wxString event = theTransition.GetTrigger();

if (event.empty() && !theTransition.IsInternalTransition())
{
	wxString guard = theTransition.GetGuard();

	fprintf(implementationFile, "\t// %s\n", (const char*)theTransition.GetLabel().c_str());

	if (guard.empty())
		fprintf(implementationFile, "\tif (1)\n\t{\n");
	else
		fprintf(implementationFile, "\tif (%s_impl_%s(me, theEvent))\n\t{\n", 
                                    (const char*)theStatechart.GetName().c_str(),
                                    (const char*)theTransition.GetGuard().c_str());

	std::list<wxString> aList = theTransition.GetActions();

	if (!aList.empty())
		fprintf(implementationFile, "\t\t// Actions\n");

	for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end();  iter++)
		fprintf(implementationFile, "\t\t%s_impl_%s(me, theEvent);\n",
                                    (const char*)theStatechart.GetName().c_str(),
                                    (const char*)(*iter).c_str());

	wxString nextState = theTransition.GetDestination();

    if (!theState.GetExitAction().empty())
    {
        fprintf(implementationFile, "\t\t// exit action\n");
        fprintf(implementationFile, "\t\t%s(theEvent);\n", (const char*)theState.GetExitAction().c_str());
    }
    if (!theState.GetTimeout().empty())
    {
        fprintf(implementationFile, "\t\t// Stop Timer\n");
        fprintf(implementationFile, "\t\tACF_cancelTimeout(&me->MessageReceiver_base);\n");
    }
    
	fprintf(implementationFile, "\t\t// next state\n");
    fprintf(implementationFile, "\t\tme->nextState = &%s_Enter_%s;\n",
                                (const char*)theStatechart.GetName().c_str(),
                                (const char*)nextState.c_str());

	fprintf(implementationFile,"\t}\n\telse\n");
}
