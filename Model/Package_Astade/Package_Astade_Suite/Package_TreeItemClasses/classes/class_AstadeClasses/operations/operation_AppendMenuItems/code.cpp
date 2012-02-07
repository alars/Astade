//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeClasses] ~~

AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDCLASS, wxS("add class"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDMANUALCLASS, wxS("add manual class"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDLIBCLASS, wxS("add lib class"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDSTATECHART, wxS("add statechart"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_OBJECTMODELDIALOG, wxS("Object model diagram"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all class folders"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
