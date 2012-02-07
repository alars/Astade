//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeConstructor] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDPARAMETERS, wxS("add parameters"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename element file"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename everything"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->HasParameters())
	aPopUp.Enable(ID_ADDPARAMETERS, false);

