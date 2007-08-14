aPopUp.Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDPARAMETERS,"add parameters",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
	aPopUp.Append(ID_RENAMEELEMENT,"Rename element file",wxEmptyString, wxITEM_NORMAL);

aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

/*if (	(dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasParameters())
	||	(dynamic_cast<AdeDestructor*>(myModelElement) != NULL))
	aPopUp.Enable(ID_ADDPARAMETERS, false);
*/

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasParameters())
	aPopUp.Enable(ID_ADDPARAMETERS, false);

