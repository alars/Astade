//~~ void CodeStatechart(AdeStatechart& theStatechart) [StateChartCoderVSM] ~~
fprintf(implementationFile, "#define _CLASSNAME %s\n\n", (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "// Include of event primitive defines\n");
fprintf(specificationFile, "#include %s\n\n", (const char*)theStatechart.GetEventType().c_str());
fprintf(specificationFile, "// Include of VirtualStateMachine base class\n");
fprintf(specificationFile, "#include \"VirtualStateMachine.h\"\n");


fprintf(implementationFile, "// default trace macros\n");
fprintf(implementationFile, "#ifndef NOTIFY_CONSTRUCTOR\n");
fprintf(implementationFile, "#  define NOTIFY_CONSTRUCTOR(a,b,c)\n") ;
fprintf(implementationFile, "#endif\n");

fprintf(implementationFile, "#ifndef NOTIFY_DESTRUCTOR\n");
fprintf(implementationFile, "#  define NOTIFY_DESTRUCTOR(a,b)\n");
fprintf(implementationFile, "#endif\n");

fprintf(implementationFile, "#ifndef NOTIFY_FUNCTION_CALL\n");
fprintf(implementationFile, "#  define NOTIFY_FUNCTION_CALL(a,b,c,d,e)\n");
fprintf(implementationFile, "#endif\n");

fprintf(implementationFile, "#ifndef NOTIFY_RETURN_VALUE\n");
fprintf(implementationFile, "#  define NOTIFY_RETURN_VALUE(a)\n");
fprintf(implementationFile, "#endif\n");

fprintf(implementationFile, "#ifndef NOTIFY_EVENT_RECEIVE\n");
fprintf(implementationFile, "#  define NOTIFY_EVENT_RECEIVE(a,b,c)\n");
fprintf(implementationFile, "#endif\n");

fprintf(implementationFile, "#ifndef NOTIFY_EVENT_TRANSMIT\n");
fprintf(implementationFile, "#  define NOTIFY_EVENT_TRANSMIT(a,b,c)\n");
fprintf(implementationFile, "#endif\n");

fprintf(implementationFile, "#ifndef NOTIFY_STATE_CHANGE\n");
fprintf(implementationFile, "#  define NOTIFY_STATE_CHANGE(a,b)\n");
fprintf(implementationFile, "#endif\n\n");


fprintf(specificationFile, "class %s : public CVirtualStateMachine\n{\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "\tpublic:\n");
CodeTriggerIDs(theStatechart);
CodeConstructor(theStatechart);

fprintf(specificationFile, "\n\tprotected:\n");

CodeActions(theStatechart);
CodeGuards(theStatechart);
CodeTimeouts(theStatechart);

fprintf(specificationFile, "\n\tprivate:\n");

CodeNoState(theStatechart);
CodeEnterPointer(theStatechart);
CodeEnterFunction(theStatechart);

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(theStatechart, *aState);
		CodeEnterState(theStatechart, *aState);
	}
	delete aElement;
}

// Timer
fprintf(specificationFile, "\t\t//! \\brief Here's the ID of the running timer (if any). 0 otherwise.\n");
fprintf(specificationFile, "\t\tlong m_RunningTimer;\n");

fprintf(specificationFile, "};\n");
