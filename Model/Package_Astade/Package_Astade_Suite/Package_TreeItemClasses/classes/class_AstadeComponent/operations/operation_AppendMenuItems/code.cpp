//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeComponent] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET | COPY_SOURCE);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ACTIVECONFIGURATION, wxS("set as active component"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDCONFIGURATION, wxS("add configuration"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDUSECASEDS, wxS("add usecase diagrams"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDSEQUENCES, wxS("add sequence diagrams"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_REGENERATE, wxS("regenerate all"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_EDITPROLOGEPILOG, wxS("edit prolog/epilog"), CreatePrologEpilogMenu());
aPopUp.AppendSeparator();

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasSequences())
	aPopUp.Enable(ID_ADDSEQUENCES, false);

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename component folder"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename everything"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(-1, wxS("jump to class"), CreateJumpMenu(*(dynamic_cast<AdeComponent*>(myModelElement))));

if (dynamic_cast<AdeComponent*>(myModelElement)->IsActiveComponent())
	aPopUp.Enable(ID_ACTIVECONFIGURATION, false);
else
	aPopUp.Enable(ID_REGENERATE, false);
