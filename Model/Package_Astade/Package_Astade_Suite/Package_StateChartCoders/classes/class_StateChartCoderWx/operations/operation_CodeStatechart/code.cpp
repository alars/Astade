/////////////////////////////
// get implementation prolog
// TODO: put this into a method

fprintf(implementationFile, "// Implementation prolog\n");
InsertFile(implementationFile,"prolog.cpp",theStatechart);
fprintf(implementationFile, "// ---\n");

fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "#undef wx__DECLARE_EVT2\n");
fprintf(implementationFile, "#undef wx__DECLARE_EVT1\n");
fprintf(implementationFile, "#undef wx__DECLARE_EVT0\n");

fprintf(implementationFile, "#define wx__DECLARE_EVT2(evt, id1, id2, fn) (theEvent.GetEventType() == evt && theEvent.GetId() >= id1 && theEvent.GetId() <= id2)\n");
fprintf(implementationFile, "#define wx__DECLARE_EVT1(evt, id, fn) (theEvent.GetEventType() == evt && theEvent.GetId() == id)\n");
fprintf(implementationFile, "#define wx__DECLARE_EVT0(evt, fn) (theEvent.GetEventType() == evt)\n\n");

fprintf(specificationFile, "#ifndef __%s_h\n#  define __%s_h\n\n", (const char*)theStatechart.GetName().c_str(), (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "// Include wxWidgets\n");
fprintf(specificationFile, "#include <wx/event.h>\n");
fprintf(specificationFile, "#include <wx/timer.h>\n\n");

fprintf(specificationFile, "// specification prolog\n");
InsertFile(specificationFile,"prolog.h",theStatechart);
fprintf(specificationFile, "// ---\n");


if (!theStatechart.GetEventType().empty())
{
	fprintf(specificationFile, "// Include event ID defines\n");
	fprintf(specificationFile, "#include %s\n\n", (const char*)theStatechart.GetEventType().c_str());
}

fprintf(specificationFile, "#ifndef TIMER_ID\n#  define TIMER_ID 1\n#endif\n\n");

fprintf(specificationFile, "/**@dot\n");
StateChartDrawer::drawStatechart(theStatechart, specificationFile);
fprintf(specificationFile, "@enddot\n\n");

wxString description(theStatechart.GetDescription());
if (!description.empty())
    fprintf(specificationFile, "%s\n*/\n", (const char*)description.c_str());
else
    fprintf(specificationFile, "*/\n");

fprintf(specificationFile, "class %s : public wxTimer\n{\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "\tpublic:\n");
CodeConstructor(theStatechart);
CodeInitialize(theStatechart);
CodeTakeEvent(theStatechart);

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateFunction(theStatechart, *static_cast<AdeState*>(aElement));
	delete aElement;
}

fprintf(specificationFile, "\n\tprotected:\n");
CodeActions(theStatechart);
CodeGuards(theStatechart);
CodeTimeouts(theStatechart);

fprintf(specificationFile, "\n\tprivate:\n");
CodeNoState(theStatechart);
CodeState(theStatechart);
CodeEnterPointer(theStatechart);
CodeEnterFunction(theStatechart);
CodeNotify(theStatechart);

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


fprintf(specificationFile, "};\n");

fprintf(implementationFile, "// Implementation epilog\n");
InsertFile(implementationFile,"epilog.cpp",theStatechart);
fprintf(implementationFile, "// ---\n");

fprintf(specificationFile, "// specification epilog\n");
InsertFile(specificationFile,"epilog.h",theStatechart);
fprintf(specificationFile, "// ---\n");

fprintf(specificationFile, "#endif\n");