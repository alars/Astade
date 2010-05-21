//~~ void CodeStatechart() [StateChartCoderWx] ~~
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

impl << "// event macros" << std::endl;
impl << "#undef wx__DECLARE_EVT2" << std::endl;
impl << "#undef wx__DECLARE_EVT1" << std::endl;
impl << "#undef wx__DECLARE_EVT0" << std::endl;

impl << "#define wx__DECLARE_EVT2(evt, id1, id2, fn) (theEvent.GetEventType() == evt && theEvent.GetId() >= id1 && theEvent.GetId() <= id2)" << std::endl;
impl << "#define wx__DECLARE_EVT1(evt, id, fn) (theEvent.GetEventType() == evt && theEvent.GetId() == id)" << std::endl;
impl << "#define wx__DECLARE_EVT0(evt, fn) (theEvent.GetEventType() == evt)" << std::endl;
impl << std::endl;

impl << "// default trace macros" << std::endl;
impl << "#ifndef NOTIFY_CONSTRUCTOR" << std::endl;
impl << "#  define NOTIFY_CONSTRUCTOR(a,b,c)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_DESTRUCTOR" << std::endl;
impl << "#  define NOTIFY_DESTRUCTOR(a,b)" << std::endl;
impl << "#endif" << std::endl;

impl << "#ifndef NOTIFY_FUNCTION_CALL" << std::endl;
impl << "#  define NOTIFY_FUNCTION_CALL(a,b,c,d,e)" << std::endl;
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

spec << "// Include wxWidgets" << std::endl;
spec << "#include <wx/event.h>" << std::endl;
spec << "#include <wx/timer.h>\n" << std::endl;

if (!myAdeStatechart->GetEventType().empty())
{
	spec << "// Include event ID defines" << std::endl;
	spec << "#include "
		<< myAdeStatechart->GetEventType().c_str()
		<< std::endl;
	spec << std::endl;
}
myAdeStatechart->SetEventType("wxEvent");

spec << "#ifndef TIMER_ID" << std::endl;
spec << "#  define TIMER_ID 1" << std::endl;
spec << "#endif\n" << std::endl;

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.c_str() << std::endl;
spec << "*/" << std::endl;

spec << "class "
	<< myAdeStatechart->GetName().c_str()
	<< " : public wxTimer"
	<< std::endl;
spec << "{" << std::endl;

spec << "public:" << std::endl;
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
CodeTimeouts();

spec << "\nprivate:" << std::endl;

CodeNoState();
CodeState();
CodeEnterPointer();
CodeEnterFunction();
CodeNotify();

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
