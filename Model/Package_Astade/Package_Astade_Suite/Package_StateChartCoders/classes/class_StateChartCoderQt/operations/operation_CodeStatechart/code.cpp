//~~ void CodeStatechart() [StateChartCoderQt] ~~

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
	<< "#include \"AQF_events.h\"\n"
	<< std::endl;

spec << "// include the framework" << std::endl;
spec << "#include \"AQF_MessageReceiver.h\"\n" << std::endl;

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.utf8_str() << std::endl;
spec << "*/" << std::endl;

CodeCommonEventFiles();

spec << "class "
	<< myAdeStatechart->GetName().utf8_str()
	<< " : public AQF_MessageReceiver"
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

spec << "\n\t//! You might overload this to visualize the actual state." << std::endl;
spec << "\tvirtual void notifyNewState(const char* state){Q_UNUSED(state);};" << std::endl;

spec << "\n\t//! You might overload this to handle terminate diiferent than with delete." << std::endl;
spec << "\tvirtual void terminate(){delete this;};" << std::endl;

spec << "\nprivate:" << std::endl;

CodeNoState();
CodeState();
CodeEnterPointer();
CodeEnterFunction();

impl << std::endl;

for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		CodeStateFunction(*aState, *myAdeStatechart);
		CodeEnterState(*aState, *myAdeStatechart);
	}
	delete anElement;
}

spec << "};\n"
	 << std::endl;

spec << "\n// specification epilog" << std::endl;
InsertFile(spec, wxFileName(wxS("epilog.h")));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName(wxS("epilog.cpp")));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h"
	<< std::endl;
