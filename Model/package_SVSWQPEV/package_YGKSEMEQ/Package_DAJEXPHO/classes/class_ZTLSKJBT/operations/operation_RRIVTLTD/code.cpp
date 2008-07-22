/////////////////////////////
// get implementation prolog
// TODO: put this into a method
wxFileName PrefixName(theStatechart.GetFileName());
PrefixName.SetFullName("prolog.cpp");
wxTextFile Gprefixtext(PrefixName.GetFullPath());
if (Gprefixtext.Exists())
	Gprefixtext.Open();
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		fprintf(implementationFile,"%s\n",(const char*)str.c_str());
	if (!str.empty())
		fprintf(implementationFile,"%s\n",(const char*)str.c_str());
		fprintf(implementationFile,"\n");
}
////////

fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)theStatechart.GetName().c_str());

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
nativeTypes.Add("long double");

if (nativeTypes.Index(theStatechart.GetEventType().c_str()) == wxNOT_FOUND)
{
	fprintf(specificationFile, "// forward declaration of event class\n");
	fprintf(specificationFile, "class %s;\n\n", (const char*)theStatechart.GetEventType().c_str());
}

fprintf(specificationFile, "/**@dot\n");
StateChartDrawer::drawStatechart(theStatechart, specificationFile);
fprintf(specificationFile, "@enddot\n\n");

wxString description(theStatechart.GetDescription());
if (!description.empty())
    fprintf(specificationFile, "%s\n*/\n", (const char*)description.c_str());
else
    fprintf(specificationFile, "*/\n");

/////////////////////////////
// get specification prolog
// TODO: put this into a method
PrefixName=theStatechart.GetFileName();
PrefixName.SetFullName("prolog.h");
Gprefixtext.Close();
Gprefixtext.Open(PrefixName.GetFullPath());
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		fprintf(specificationFile,"%s\n",(const char*)str.c_str());
	if (!str.empty())
		fprintf(specificationFile,"%s\n",(const char*)str.c_str());
		fprintf(specificationFile,"\n");
}
////////

fprintf(specificationFile, "class %s\n{\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "\tpublic:\n");
CodeTriggerIDs(theStatechart);
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

fprintf(specificationFile, "\n\tprivate:\n");

CodeNoState(theStatechart);
CodeState(theStatechart);
CodeEnterPointer(theStatechart);
CodeEnterFunction(theStatechart);

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

fprintf(specificationFile,"};\n");
/////////////////////////////
// get specification epilog
// TODO: put this into a method
PrefixName=theStatechart.GetFileName();
PrefixName.SetFullName("epilog.h");
Gprefixtext.Open(PrefixName.GetFullPath());
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		fprintf(specificationFile,"%s\n",(const char*)str.c_str());
	if (!str.empty())
		fprintf(specificationFile,"%s\n",(const char*)str.c_str());
		fprintf(specificationFile,"\n");
}
/////////////////////////////
// get implementation epilog
// TODO: put this into a method
PrefixName=theStatechart.GetFileName();
PrefixName.SetFullName("epilog.cpp");
Gprefixtext.Open(PrefixName.GetFullPath());
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		fprintf(implementationFile,"%s\n",(const char*)str.c_str());
	if (!str.empty())
		fprintf(implementationFile,"%s\n",(const char*)str.c_str());
		fprintf(implementationFile,"\n");
}
////////
