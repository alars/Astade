fprintf(specificationFile, "//! \\brief This is the enter function for state %s.\n", (const char*)theState.GetName().c_str());
fprintf(specificationFile, "void %s_Enter_%s(%s* me, %s* theEvent);\n\n",
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theState.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "void %s_Enter_%s(%s* me, %s* theEvent)\n{\n", 
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theState.GetName().c_str(),
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	fprintf(implementationFile, "\t//Call Entry Action.\n");
	fprintf(implementationFile, "\t%s_impl_%s(me, theEvent);\n",
                                (const char*)theStatechart.GetName().c_str(),
                                (const char*)EntryAction.c_str());
}

fprintf(implementationFile, "\t// maybe trace the state entering\n");
fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\t\tACF_tracePtr(me);\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.Name);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\" >>> %s\\n\");\n",(const char*)theState.GetName().c_str());
fprintf(implementationFile, "\t#endif\n");

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	if (!aTimeout.empty())
	{
		fprintf(implementationFile, "\t//Start Timer.\n");
		fprintf(implementationFile, "\tACF_scheduleTimeout(&me->MessageReceiver_base, %s);\n",
                                    (const char*)aTimeout.c_str());
	}
}

fprintf(implementationFile, "\t//Set the new state.\n");
fprintf(implementationFile, "\tme->theState = &%s_%s;\n", 
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theState.GetName().c_str());

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (!aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart, theState, *aTransition);
	}
	delete aElement;
}

for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		if (aTransition->GetGuard().empty())
			CodeEventlessTransition(theStatechart, theState, *aTransition);
	}
	delete aElement;
}

fprintf(implementationFile, "\tme->nextState = 0; // We stay in this state\n");
fprintf(implementationFile, "}\n\n");
