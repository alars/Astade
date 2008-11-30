aPopUp.Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();

if (!static_cast<AdeClass*>(myModelElement)->IsLibClass())
{
	aPopUp.Append(ID_GENCODE,"generate code",wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_ROUNDTRIPCODE,"roundtrip code",wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();

	aPopUp.Append(ID_ADDRELATION,"start relation to ...",wxEmptyString, wxITEM_NORMAL);

	if (!AstadeClass::GetRelationSourceName().empty())
		aPopUp.Append(ID_COMPLETERELATION, "complete relation from " + AstadeClass::GetRelationSourceName(), wxEmptyString, wxITEM_NORMAL);

	aPopUp.AppendSeparator();

	aPopUp.Append(ID_ADDATTRIBUTES,"add attributes",wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_ADDOPERATIONS,"add operations",wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_ADDTYPES,"add types",wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_OBJECTMODELDIALOG,"Object model diagram",wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_EDITIMPLEMENTATION,"edit implementation",wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_EDITSPECIFICATION,"edit specification",wxEmptyString, wxITEM_NORMAL);

	aPopUp.Append(ID_EDITPROLOGEPILOG,"edit prolog/epilog",CreatePrologEpilogMenu());

	aPopUp.AppendSeparator();
	aPopUp.Append(-1,"show components",CreateUsedMenu(*myModelElement));
        aPopUp.AppendSeparator();
	if (dynamic_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
	{
		aPopUp.Append(ID_REMOVEFROMCOMPONENT,"remove from active component",wxEmptyString, wxITEM_NORMAL);
	}
	else
	{
		if (wxConfigBase::Get()->Read("TreeView/ActiveComponent") != "none")
			aPopUp.Append(ID_ADDTOCOMPONENT,"add to active component",wxEmptyString, wxITEM_NORMAL);
	}

	aPopUp.AppendSeparator();

	if (!dynamic_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
	{
		aPopUp.Enable(ID_GENCODE,false);
		aPopUp.Enable(ID_ROUNDTRIPCODE,false);
		aPopUp.Enable(ID_EDITIMPLEMENTATION,false);
		aPopUp.Enable(ID_EDITSPECIFICATION,false);
	}

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasAttributes())
		aPopUp.Enable(ID_ADDATTRIBUTES,false);

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasOperations())
		aPopUp.Enable(ID_ADDOPERATIONS,false);

	if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasTypes())
		aPopUp.Enable(ID_ADDTYPES,false);
}
else if (!AstadeClass::GetRelationSourceName().empty())
{
	aPopUp.Append(ID_COMPLETERELATION, "complete relation from " + AstadeClass::GetRelationSourceName(), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
	aPopUp.Append(ID_RENAMEELEMENT,"Rename class folder",wxEmptyString, wxITEM_NORMAL);

aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);
