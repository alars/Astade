// get implementation prolog
InsertFile(implementationFile,"prolog.cpp",*myAdeStatechart);

fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)myAdeStatechart->GetName().c_str());

wxArrayString nativeTypes;

nativeTypes.Add("void");
nativeTypes.Add("int");
nativeTypes.Add("float");
nativeTypes.Add("double");
nativeTypes.Add("char");
nativeTypes.Add("bool");
nativeTypes.Add("wchar_t");

nativeTypes.Add("unsigned char");
nativeTypes.Add("signed char");
nativeTypes.Add("unsigned int");
nativeTypes.Add("unsigned");
nativeTypes.Add("signed int");
nativeTypes.Add("signed");
nativeTypes.Add("short int");
nativeTypes.Add("unsigned short int");
nativeTypes.Add("signed short int");
nativeTypes.Add("long int");
nativeTypes.Add("long");
nativeTypes.Add("signed long int");
nativeTypes.Add("unsigned long int");
nativeTypes.Add("signed long");
nativeTypes.Add("unsigned long");
nativeTypes.Add("long double");
nativeTypes.Add("long long");
nativeTypes.Add("signed long long");
nativeTypes.Add("unsigned long long");

// get specification prolog
InsertFile(specificationFile,"prolog.h",*myAdeStatechart);

if (myAdeStatechart->GetEventType() == "std::string")
{
	fprintf(specificationFile, "// include declaration of event class\n");
	fprintf(specificationFile, "#include <string>\n\n");
}
else if (nativeTypes.Index(myAdeStatechart->GetEventType().c_str()) == wxNOT_FOUND)
{
	fprintf(specificationFile, "// forward declaration of event class\n");
	fprintf(specificationFile, "class %s;\n\n", (const char*)myAdeStatechart->GetEventType().c_str());
}

fprintf(specificationFile, "/**@dot\n");
StateChartDrawer::drawStatechart(*myAdeStatechart, specificationFile);
fprintf(specificationFile, "@enddot\n\n");

wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
    fprintf(specificationFile, "%s\n*/\n", (const char*)description.c_str());
else
    fprintf(specificationFile, "*/\n");

fprintf(specificationFile, "class %s\n{\n", (const char*)myAdeStatechart->GetName().c_str());

fprintf(specificationFile, "\tpublic:\n");
CodeTriggerIDs(*myAdeStatechart);
CodeConstructor(*myAdeStatechart);
CodeInitialize(*myAdeStatechart);
CodeTakeEvent(*myAdeStatechart);

AdeElementIterator it;
for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateFunction(*myAdeStatechart, *static_cast<AdeState*>(aElement));
	delete aElement;
}

fprintf(specificationFile, "\n\tprotected:\n");

CodeActions(*myAdeStatechart);
CodeGuards(*myAdeStatechart);

fprintf(specificationFile, "\n\tprivate:\n");

CodeNoState(*myAdeStatechart);
CodeState(*myAdeStatechart);
CodeEnterPointer(*myAdeStatechart);
CodeEnterFunction(*myAdeStatechart);

for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(*myAdeStatechart, *aState);
		CodeEnterState(*myAdeStatechart, *aState);
	}
	delete aElement;
}

fprintf(specificationFile,"};\n");
/////////////////////////////
// get specification epilog
InsertFile(specificationFile,"epilog.h",*myAdeStatechart);
/////////////////////////////
// get implementation epilog
InsertFile(implementationFile,"epilog.cpp",*myAdeStatechart);
////////
