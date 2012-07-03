//~~ void CodeStatechart() [StateChartCoderC] ~~

spec << "#ifndef __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h"
	<< std::endl;
spec << "#  define __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h\n"
	<< std::endl;

spec << "// specification prolog" << std::endl;
InsertFile(spec, wxFileName(wxS("prolog.h")));
impl << "// implementation prolog" << std::endl;
InsertFile(impl, wxFileName(wxS("prolog.cpp")));

impl << "#include \""
	<< myAdeStatechart->GetName().utf8_str()
	<< ".h\"\n"
	<< std::endl;

wxArrayString nativeTypes;

nativeTypes.Add(wxS("void"));
nativeTypes.Add(wxS("int"));
nativeTypes.Add(wxS("float"));
nativeTypes.Add(wxS("double"));
nativeTypes.Add(wxS("char"));
nativeTypes.Add(wxS("bool"));
nativeTypes.Add(wxS("wchar_t"));

nativeTypes.Add(wxS("unsigned char"));
nativeTypes.Add(wxS("signed char"));
nativeTypes.Add(wxS("unsigned int"));
nativeTypes.Add(wxS("unsigned"));
nativeTypes.Add(wxS("signed int"));
nativeTypes.Add(wxS("signed"));
nativeTypes.Add(wxS("short int"));
nativeTypes.Add(wxS("unsigned short int"));
nativeTypes.Add(wxS("signed short int"));
nativeTypes.Add(wxS("long int"));
nativeTypes.Add(wxS("long"));
nativeTypes.Add(wxS("signed long int"));
nativeTypes.Add(wxS("unsigned long int"));
nativeTypes.Add(wxS("long double"));

if (nativeTypes.Index(myAdeStatechart->GetEventType()) == wxNOT_FOUND)
{
	spec << "// include of event type" << std::endl;
	spec << "#include \""
		<< myAdeStatechart->GetEventType().utf8_str()
		<< ".h\"\n"
		<< std::endl;
}

spec << "// include of the handle class" << std::endl;
spec << "#include \""
	<< myAdeStatechart->GetName().utf8_str()
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
	spec << description.utf8_str() << std::endl;
spec << "*/\n" << std::endl;

CodeTriggerIDs();

spec << "typedef struct "
	<< myAdeStatechart->GetName().utf8_str()
	<< std::endl;
spec << "{" << std::endl;

CodeState();
CodeEnterPointer();
CodeHandlePointer();

spec << "} "
	<< myAdeStatechart->GetName().utf8_str()
	<< ";\n"
	<< std::endl;

CodeInitialize();
CodeTakeEvent();

CodeEnterFunction();

AdeElementIterator it;
for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(anElement);
		CodeStateFunction(*aState);
		CodeEnterState(*aState);
	}
	delete anElement;
}

for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateFunction(*static_cast<AdeState*>(anElement));
	delete anElement;
}

spec << "#ifdef __cplusplus" << std::endl;
spec << "}" << std::endl;
spec << "#endif" << std::endl;

spec << "\n// specification epilog" << std::endl;
InsertFile(spec, wxFileName(wxS("epilog.h")));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName(wxS("epilog.cpp")));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h"
	<< std::endl;
