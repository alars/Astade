//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeParameters] ~~

AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDPARAMETER, wxS("add parameter"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all parameters"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
