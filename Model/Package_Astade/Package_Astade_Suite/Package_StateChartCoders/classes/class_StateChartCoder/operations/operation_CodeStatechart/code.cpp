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
nativeTypes.Add("signed long");
nativeTypes.Add("unsigned long");
nativeTypes.Add("long double");
nativeTypes.Add("long long");
nativeTypes.Add("signed long long");
nativeTypes.Add("unsigned long long");

if (myAdeStatechart->GetEventType() == "std::string")
{
	spec << "// include declaration of event class" << std::endl;
	spec << "#include <string>\n" << std::endl;
}
else if (nativeTypes.Index(myAdeStatechart->GetEventType().c_str()) == wxNOT_FOUND)
{
	spec << "// forward declaration of event class" << std::endl;
	spec << "class "
		<< myAdeStatechart->GetEventType().c_str()
		<< ";\n"
		<< std::endl;
}

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.c_str() << std::endl;
spec << "*/" << std::endl;

spec << "class "
	<< myAdeStatechart->GetName().c_str()
	<< std::endl;
spec << "{" << std::endl;

spec << "public:" << std::endl;
CodeTriggerIDs();
CodeConstructor();
CodeInitialize();
CodeTakeEvent();

AdeElementIterator it;
for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateFunction(*dynamic_cast<AdeState*>(anElement));
	delete anElement;
}

spec << "\nprotected:" << std::endl;

CodeActions();
CodeGuards();

spec << "\nprivate:" << std::endl;

CodeNoState();
CodeState();
CodeEnterPointer();
CodeEnterFunction();

for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		CodeStateFunction(*aState);
		CodeEnterState(*aState);
	}
	delete anElement;
}

spec << "};" << std::endl;

spec << "\n// specification epilog" << std::endl;
InsertFile(spec, wxFileName("epilog.h"));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName("epilog.cpp"));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h"
	<< std::endl;
