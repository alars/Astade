//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeConnections] ~~

AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDCONNECTION, wxS("add connection"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all connections"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
