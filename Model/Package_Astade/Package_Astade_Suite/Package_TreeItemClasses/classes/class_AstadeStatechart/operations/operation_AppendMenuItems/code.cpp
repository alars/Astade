//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeStatechart] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);

if (!dynamic_cast<AdeClass*>(myModelElement)->IsTraced())
    aPopUp.Append(ID_TRACE_ON, wxS("trace on"), wxEmptyString, wxITEM_NORMAL);
else
    aPopUp.Append(ID_TRACE_OFF, wxS("trace off"), wxEmptyString, wxITEM_NORMAL);

aPopUp.AppendSeparator();

AppendCutnPaste(aPopUp, COPY_SOURCE | COPY_TARGET);
aPopUp.AppendSeparator();

aPopUp.Append(ID_GENSTATECHART, wxS("generate code"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

#if USE_RELATIONS_IN_STATECHARTS 
aPopUp.Append(ID_ADDRELATION, wxS("start relation to ..."), wxEmptyString, wxITEM_NORMAL);
#endif

if (!AstadeClass::GetRelationSourceName().empty())
{
	aPopUp.Append(ID_COMPLETERELATION, wxS("complete relation from ") + AstadeClass::GetRelationSourceName(), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_ADDSTATE, wxS("add state"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

aPopUp.Append(ID_STATECHART, wxS("Statechart"), wxEmptyString, wxITEM_NORMAL);

aPopUp.AppendSeparator();
aPopUp.Append(ID_EDITIMPLEMENTATION, wxS("edit implementation"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_EDITSPECIFICATION, wxS("edit specification"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_EDITPROLOGEPILOG, wxS("edit prolog/epilog"), CreatePrologEpilogMenu());
aPopUp.AppendSeparator();
aPopUp.Append(-1, wxS("show components"), CreateUsedMenu(*myModelElement));
aPopUp.AppendSeparator();
if (dynamic_cast<AdeStatechart*>(myModelElement)->IsInActiveComponent())
	aPopUp.Append(ID_REMOVEFROMCOMPONENT, wxS("remove from active component"), wxEmptyString, wxITEM_NORMAL);
else if (wxConfigBase::Get()->Read(wxS("TreeView/ActiveComponent")) != wxS("none"))
	aPopUp.Append(ID_ADDTOCOMPONENT, wxS("add to active component"), wxEmptyString, wxITEM_NORMAL);

aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename statechart folder"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename everything"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);

if (!dynamic_cast<AdeStatechart*>(myModelElement)->IsInActiveComponent())
{
	aPopUp.Enable(ID_GENSTATECHART, false);
	aPopUp.Enable(ID_EDITIMPLEMENTATION, false);
	aPopUp.Enable(ID_EDITSPECIFICATION, false);
}
