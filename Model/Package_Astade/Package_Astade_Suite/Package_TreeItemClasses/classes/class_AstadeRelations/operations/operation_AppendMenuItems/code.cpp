//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeRelations] ~~

AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDRELATION, wxS("start relation to ..."), wxEmptyString, wxITEM_NORMAL);
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all relations"), wxEmptyString, wxITEM_NORMAL);
}
