AppendCutnPaste(aPopUp, COPY_TARGET);

aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDOPERATION,"add operation",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDCONSTRUCTOR,"add constructor",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDDESTRUCTOR,"add destructor",wxEmptyString, wxITEM_NORMAL);
aPopUp.Enable(ID_ADDDESTRUCTOR, !static_cast<AdeDirectoryElement*>(myModelElement)->HasDestructor());

wxMenu* overloadMenu = CreateOverloadMenu();
if (overloadMenu->GetMenuItemCount() > 0)
{
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_OVERLOADMENU,"overload operation", CreateOverloadMenu());
}
else
{
	delete overloadMenu;
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_OVERLOADMENU,"overload operation",wxEmptyString, wxITEM_NORMAL);
	aPopUp.Enable(ID_OVERLOADMENU, false);
}

aPopUp.Append(ID_REENGINEER,"reengineer from clipboard",wxEmptyString, wxITEM_NORMAL);
aPopUp.Enable(ID_REENGINEER, ParseClipboard());

aPopUp.AppendSeparator();
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENTS,"Rename all operations",wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}
aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);
