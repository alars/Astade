fprintf(implementationFile, "#define _CLASSNAME %s\n\n", (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "// Include of event primitive defines\n");
fprintf(specificationFile, "#include %s\n\n", (const char*)theStatechart.GetEventType().c_str());
fprintf(specificationFile, "// Include of VirtualStateMachine base class\n");
fprintf(specificationFile, "#include \"VirtualStateMachine.h\"\n");

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
