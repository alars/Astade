//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeOperations] ~~

AppendCutnPaste(aPopUp, COPY_TARGET);

aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDOPERATION, wxS("add operation"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDCONSTRUCTOR, wxS("add constructor"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDDESTRUCTOR, wxS("add destructor"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Enable(ID_ADDDESTRUCTOR, !static_cast<AdeDirectoryElement*>(myModelElement)->HasDestructor());

wxMenu* overloadMenu = CreateOverloadMenu();
if (overloadMenu->GetMenuItemCount() > 0)
{
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_OVERLOADMENU, wxS("overload operation"),  CreateOverloadMenu());
}
else
{
	delete overloadMenu;
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_OVERLOADMENU, wxS("overload operation"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Enable(ID_OVERLOADMENU, false);
}

aPopUp.Append(ID_REENGINEER, wxS("reengineer from clipboard"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Enable(ID_REENGINEER, ParseClipboard());

aPopUp.AppendSeparator();
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENTS, wxS("Rename all operations"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
