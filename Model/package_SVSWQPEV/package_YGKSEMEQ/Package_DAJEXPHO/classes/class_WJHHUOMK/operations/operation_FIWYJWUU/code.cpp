fprintf(specificationFile, "\t\t//! \\brief This is the enter function for state %s.\n", (const char*)theState.GetName().c_str());
fprintf(specificationFile, "\t\tvoid Enter_%s(CMessage& message);\n\n", (const char*)theState.GetName().c_str());

fprintf(implementationFile, "void %s::Enter_%s(CMessage& message)\n{\n", (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str());

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	fprintf(implementationFile, "\t//Start Timer.\n");
	fprintf(implementationFile, "\tif (m_RunningTimer)\n\t\tCMessage::Delete(m_RunningTimer);\n");
	fprintf(implementationFile, "\tm_RunningTimer = NEWMESSAGE(dIID_VFSM_MSG_AbbruchTimer)->Send(0,%s);\n\n", (const char*)aTimeout.c_str());
}

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	fprintf(implementationFile, "\t//Call Entry Action.\n");
	fprintf(implementationFile, "\t%s(message);\n", (const char*)EntryAction.c_str());
}

fprintf(implementationFile, "\t//Set the new state.\n");
fprintf(implementationFile, "\tSETSTATE(%s);\n", (const char*)theState.GetName().c_str());


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

fprintf(implementationFile, "\tnextState = 0; // We stay in this state\n");

fprintf(implementationFile, "}\n\n");
