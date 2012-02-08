//~~ void CodeStatechart() [StateChartCoderACFp] ~~
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

impl << "#include \""
	<< myAdeStatechart->GetName().c_str()
	<< ".h\"\n"
	<< "#include \"ACF_events.h\"\n"
	<< std::endl;

spec << "// include the framework" << std::endl;
spec << "#include \"ACF.h\"\n"
	<< "#include \"ACF_state_machine_base.h\"\n"
    << std::endl;

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.c_str() << std::endl;
spec << "*/" << std::endl;

CodeCommonEventFiles();

spec << "class "
	<< myAdeStatechart->GetName().c_str()
	<< " : public ACF_state_machine_base"
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
spec << "\tvirtual void notifyNewState(const char* state){};" << std::endl;

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
		CodeStateFunction(*aState);
		CodeEnterState(*aState);
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
	<< myAdeStatechart->GetName().c_str()
	<< "_h"
	<< std::endl;
