//~~ void CodeStatechart() [StateChartCoderC] ~~

spec << "#ifndef __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h"
	<< std::endl;
spec << "#  define __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h\n"
	<< std::endl;

spec << "// specification prolog" << std::endl;
InsertFile(spec, wxFileName("prolog.h"));
impl << "// implementation prolog" << std::endl;
InsertFile(impl, wxFileName("prolog.cpp"));

impl << "#include \""
	<< myAdeStatechart->GetName().c_str()
	<< ".h\"\n"
	<< std::endl;

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

if (nativeTypes.Index(myAdeStatechart->GetEventType().c_str()) == wxNOT_FOUND)
{
	spec << "// include of event type" << std::endl;
	spec << "#include \""
		<< myAdeStatechart->GetEventType().c_str()
		<< ".h\"\n"
		<< std::endl;
}

spec << "// include of the handle class" << std::endl;
spec << "#include \""
	<< myAdeStatechart->GetName().c_str()
	<< "_impl.h\"\n"
	<< std::endl;

spec << "#ifdef __cplusplus" << std::endl;
spec << "extern \"C\" {" << std::endl;
spec << "#endif\n" << std::endl;

spec << "/**@dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.c_str() << std::endl;
spec << "*/\n" << std::endl;

CodeTriggerIDs();

spec << "typedef struct "
	<< myAdeStatechart->GetName().c_str()
	<< std::endl;
spec << "{" << std::endl;

CodeState();
CodeEnterPointer();
CodeHandlePointer();

spec << "} "
	<< myAdeStatechart->GetName().c_str()
	<< ";\n"
	<< std::endl;

CodeInitialize();
CodeTakeEvent();

CodeEnterFunction();

AdeElementIterator it;
for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(*aState);
		CodeEnterState(*aState);
	}
	delete aElement;
}

for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateFunction(*static_cast<AdeState*>(aElement));
	delete aElement;
}

spec << "#ifdef __cplusplus" << std::endl;
spec << "}" << std::endl;
spec << "#endif" << std::endl;

spec << "\n// specification epilog" << std::endl;
InsertFile(spec, wxFileName("epilog.h"));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName("epilog.cpp"));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h"
	<< std::endl;
