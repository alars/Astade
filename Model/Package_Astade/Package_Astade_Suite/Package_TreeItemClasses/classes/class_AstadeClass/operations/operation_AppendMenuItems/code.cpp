//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeClass] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);

if (!static_cast<AdeClass*>(myModelElement)->IsLibClass())
{
    if (!dynamic_cast<AdeClass*>(myModelElement)->IsTraced())
	    aPopUp.Append(ID_TRACE_ON, wxS("trace on"), wxEmptyString, wxITEM_NORMAL);
    else
	    aPopUp.Append(ID_TRACE_OFF, wxS("trace off"), wxEmptyString, wxITEM_NORMAL);
}

aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();

if (!static_cast<AdeClass*>(myModelElement)->IsLibClass())
{
	aPopUp.Append(ID_GENCODE, wxS("generate code"), wxEmptyString, wxITEM_NORMAL);
	if (!static_cast<AdeClass*>(myModelElement)->IsManualClass())
	{
		aPopUp.Append(ID_ROUNDTRIPCODE, wxS("roundtrip code"), wxEmptyString, wxITEM_NORMAL);
	}
	aPopUp.AppendSeparator();

	if (!static_cast<AdeClass*>(myModelElement)->IsManualClass())
	{
		aPopUp.Append(ID_ADDRELATION, wxS("start relation to ..."), wxEmptyString, wxITEM_NORMAL);
	}

	if (!AstadeClass::GetRelationSourceName().empty())
		aPopUp.Append(ID_COMPLETERELATION, wxS("complete relation from ") + AstadeClass::GetRelationSourceName(), wxEmptyString, wxITEM_NORMAL);

	aPopUp.AppendSeparator();

	if (!static_cast<AdeClass*>(myModelElement)->IsManualClass())
	{
		aPopUp.Append(ID_ADDATTRIBUTES, wxS("add attributes"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.Append(ID_ADDOPERATIONS, wxS("add operations"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.Append(ID_ADDTYPES, wxS("add types"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.Append(ID_ADDPORTS, wxS("add ports"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.Append(ID_ADDCONNECTIONS, wxS("add connections"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.AppendSeparator();
		aPopUp.Append(ID_OBJECTMODELDIALOG, wxS("Object model diagram"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.Append(ID_COMPOSITESTRUCTUREDIAGRAM, wxS("Composite structure diagram"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.AppendSeparator();
	}
	aPopUp.Append(ID_EDITIMPLEMENTATION, wxS("edit implementation"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_EDITSPECIFICATION, wxS("edit specification"), wxEmptyString, wxITEM_NORMAL);

	aPopUp.Append(ID_EDITPROLOGEPILOG, wxS("edit prolog/epilog"), CreatePrologEpilogMenu());

	aPopUp.AppendSeparator();
	aPopUp.Append(-1, wxS("show components"), CreateUsedMenu(*myModelElement));
	aPopUp.AppendSeparator();
	if (dynamic_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
	{
		aPopUp.Append(ID_REMOVEFROMCOMPONENT, wxS("remove from active component"), wxEmptyString, wxITEM_NORMAL);
	}
	else
	{
		if (wxConfigBase::Get()->Read(wxS("TreeView/ActiveComponent")) != wxS("none"))
			aPopUp.Append(ID_ADDTOCOMPONENT, wxS("add to active component"), wxEmptyString, wxITEM_NORMAL);
	}

	aPopUp.AppendSeparator();

	if (!dynamic_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
	{
		aPopUp.Enable(ID_GENCODE, false);
		aPopUp.Enable(ID_ROUNDTRIPCODE, false);
		aPopUp.Enable(ID_EDITIMPLEMENTATION, false);
		aPopUp.Enable(ID_EDITSPECIFICATION, false);
	}

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasAttributes())
		aPopUp.Enable(ID_ADDATTRIBUTES, false);

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasOperations())
		aPopUp.Enable(ID_ADDOPERATIONS, false);

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasTypes())
		aPopUp.Enable(ID_ADDTYPES, false);

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasPorts())
		aPopUp.Enable(ID_ADDPORTS, false);

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasConnections())
		aPopUp.Enable(ID_ADDCONNECTIONS, false);
}
else if (!AstadeClass::GetRelationSourceName().empty())
{
	aPopUp.Append(ID_COMPLETERELATION, wxS("complete relation from ") + AstadeClass::GetRelationSourceName(), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename class folder"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename everything"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
