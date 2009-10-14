aPopUp.Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET | COPY_SOURCE);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ACTIVECONFIGURATION,"set as active component",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDCONFIGURATION,"add configuration",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDUSECASEDS,"add usecase diagrams",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDSEQUENCES,"add sequence diagrams",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_REGENERATE,"regenerate all",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_EDITPROLOGEPILOG,"edit prolog/epilog",CreatePrologEpilogMenu());
aPopUp.AppendSeparator();

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasSequences())
	aPopUp.Enable(ID_ADDSEQUENCES,false);

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT,"Rename component folder",wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(-1,"jump to class", CreateJumpMenu(*(dynamic_cast<AdeComponent*>(myModelElement))));

if (dynamic_cast<AdeComponent*>(myModelElement)->IsActiveComponent())
	aPopUp.Enable(ID_ACTIVECONFIGURATION, false);
else
	aPopUp.Enable(ID_REGENERATE, false);
