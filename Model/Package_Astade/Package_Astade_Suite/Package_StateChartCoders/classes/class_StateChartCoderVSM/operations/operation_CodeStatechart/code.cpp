//~~ void CodeStatechart() [StateChartCoderVSM] ~~

spec << "#ifndef __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h"
	<< std::endl;
spec << "#  define __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h\n"
	<< std::endl;

spec << "// specification prolog" << std::endl;
InsertFile(spec, wxFileName(wxS("prolog.h")));
impl << "// implementation prolog" << std::endl;
InsertFile(impl, wxFileName(wxS("prolog.cpp")));

impl << "#define _CLASSNAME "
	<< myAdeStatechart->GetName().c_str()
	<< "\n"
	<< std::endl;
impl << "#include \""
	<< myAdeStatechart->GetName().c_str()
	<< ".h\"\n"
	<< std::endl;

spec << "// Include of event primitive defines" << std::endl;
spec << "#include "
	<< myAdeStatechart->GetEventType().c_str()
	<< "\n"
	<< std::endl;
spec << "// Include of VirtualStateMachine base class" << std::endl;
spec << "#include \"VirtualStateMachine.h\"" << std::endl;

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
impl << "#endif\n" << std::endl;

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.c_str() << std::endl;
spec << "*/" << std::endl;

myAdeStatechart->SetEventType(wxS("CMessage"));

spec << "class "
	<< myAdeStatechart->GetName().c_str()
	<< " : public CVirtualStateMachine"
	<< std::endl;
spec << "{" << std::endl;

spec << "public:" << std::endl;
CodeTriggerIDs();
CodeConstructor();

spec << "\nprotected:" << std::endl;

CodeActions();
CodeGuards();
CodeTimeouts();

spec << "\nprivate:" << std::endl;

CodeNoState();
CodeEnterPointer();
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

spec << "\t//! @brief Here's the ID of the running timer (if any). 0 otherwise." << std::endl;
spec << "\tlong m_RunningTimer;" << std::endl;

spec << "};" << std::endl;

spec << "\n// specification epilog" << std::endl;
InsertFile(spec, wxFileName(wxS("epilog.h")));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName(wxS("epilog.cpp")));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().c_str()
	<< "_h"
	<< std::endl;
