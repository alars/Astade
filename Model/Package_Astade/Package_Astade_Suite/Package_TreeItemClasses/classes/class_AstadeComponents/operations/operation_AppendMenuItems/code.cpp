//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeComponents] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDCOMPONENT, wxS("add component"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET | COPY_SOURCE);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename components folder"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all components"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
