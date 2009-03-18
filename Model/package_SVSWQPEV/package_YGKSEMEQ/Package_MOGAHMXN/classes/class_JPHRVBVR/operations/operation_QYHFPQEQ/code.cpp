aPopUp.Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (dynamic_cast<AdeStatechart*>(myModelElement)->IsInActiveComponent())
{
	aPopUp.Append(ID_REMOVEFROMCOMPONENT,"remove from active component",wxEmptyString, wxITEM_NORMAL);
}
else
{
	if (wxConfigBase::Get()->Read("TreeView/ActiveComponent") != "none")
		aPopUp.Append(ID_ADDTOCOMPONENT,"add to active component",wxEmptyString, wxITEM_NORMAL);
}

aPopUp.Append(ID_GENSTATECHART,"generate code",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

#if USE_RELATIONS_IN_STATECHARTS 
aPopUp.Append(ID_ADDRELATION,"start relation to ...",wxEmptyString, wxITEM_NORMAL);
#endif

if (!AstadeClass::GetRelationSourceName().empty())
{
	aPopUp.Append(ID_COMPLETERELATION, "complete relation from " + AstadeClass::GetRelationSourceName(), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_ADDSTATE,"add state",wxEmptyString, wxITEM_NORMAL);

aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE | COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_STATECHART,"Statechart",wxEmptyString, wxITEM_NORMAL);

aPopUp.AppendSeparator();
aPopUp.Append(ID_EDITIMPLEMENTATION,"edit implementation",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_EDITSPECIFICATION,"edit specification",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_EDITPROLOGEPILOG,"edit prolog/epilog",CreatePrologEpilogMenu());
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT,"Rename statechart folder",wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

if (!dynamic_cast<AdeStatechart*>(myModelElement)->IsInActiveComponent())
{
	aPopUp.Enable(ID_GENSTATECHART,false);
	aPopUp.Enable(ID_EDITIMPLEMENTATION,false);
	aPopUp.Enable(ID_EDITSPECIFICATION,false);
}
