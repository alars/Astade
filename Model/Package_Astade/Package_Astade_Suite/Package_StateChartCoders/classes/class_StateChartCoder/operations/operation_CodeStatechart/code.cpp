//~~ void CodeStatechart() [StateChartCoder] ~~

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

impl << "// default trace macros" << std::endl;
impl << "#ifndef NOTIFY_CONSTRUCTOR" << std::endl;
impl << "#  define NOTIFY_CONSTRUCTOR(a,b,c)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_DESTRUCTOR" << std::endl;
impl << "#  define NOTIFY_DESTRUCTOR(a,b)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_FUNCTION_CALL" << std::endl;
impl << "#  define NOTIFY_FUNCTION_CALL(a,b,c,d,e,f)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_RETURN_VALUE" << std::endl;
impl << "#  define NOTIFY_RETURN_VALUE(a)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_EVENT_RECEIVE" << std::endl;
impl << "#  define NOTIFY_EVENT_RECEIVE(a,b,c)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_EVENT_TRANSMIT" << std::endl;
impl << "#  define NOTIFY_EVENT_TRANSMIT(a,b,c)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_STATE_CHANGE" << std::endl;
impl << "#  define NOTIFY_STATE_CHANGE(a,b)" << std::endl;
impl << "#endif" << std::endl;
impl << std::endl;


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
nativeTypes.Add(wxS("signed long"));
nativeTypes.Add(wxS("unsigned long"));
nativeTypes.Add(wxS("long double"));
nativeTypes.Add(wxS("long long"));
nativeTypes.Add(wxS("signed long long"));
nativeTypes.Add(wxS("unsigned long long"));

wxString NonConst(myAdeStatechart->GetEventType());
myAdeStatechart->GetEventType().StartsWith(wxS("const "), &NonConst);
if (NonConst == wxS("std::string"))
{
	spec << "// include declaration of event class" << std::endl;
	spec << "#include <string>\n" << std::endl;
}
else if (nativeTypes.Index(NonConst) == wxNOT_FOUND)
{
	spec << "// forward declaration of event class" << std::endl;
	spec << "class "
		<< NonConst.utf8_str()
		<< ";\n"
		<< std::endl;
}

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.utf8_str() << std::endl;
spec << "*/" << std::endl;

spec << "class "
	<< myAdeStatechart->GetName().utf8_str()
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
InsertFile(spec, wxFileName(wxS("epilog.h")));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName(wxS("epilog.cpp")));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h"
	<< std::endl;
