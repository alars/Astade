theStatechart.SetEventType("ACF_Message");
fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "// include of the framework\n");
fprintf(specificationFile, "#include \"ACF.h\"\n\n");

fprintf(specificationFile, "// include of the handle class\n");
fprintf(specificationFile, "#include \"%s_impl.h\"\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "/**@dot\n");
StateChartDrawer::drawStatechart(theStatechart, specificationFile);
fprintf(specificationFile, "@enddot\n\n");

wxString description(theStatechart.GetDescription());
if (!description.empty())
    fprintf(specificationFile, "%s\n*/\n", (const char*)description.c_str());
else
    fprintf(specificationFile, "*/\n");

fprintf(specificationFile, "typedef struct %s\n{\n", (const char*)theStatechart.GetName().c_str());
CodeState(theStatechart);
CodeEnterPointer(theStatechart);
CodeHandlePointer(theStatechart);
fprintf(specificationFile,"} %s;\n\n", (const char*)theStatechart.GetName().c_str());

CodeTriggerIDs(theStatechart);

CodeInitialize(theStatechart);
CodeTakeEvent(theStatechart);

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
