//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadePorts] ~~

AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDPORT, wxS("add port"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all ports"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
