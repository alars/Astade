//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeFiles] ~~

if (myModelElement->GetLabel() == wxS("manual"))
{
	aPopUp.Append(ID_COPYFILE, wxS("copy file"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Append(ID_MAKEMAINCPP, wxS("Make Empty main.cpp"), wxEmptyString, wxITEM_NORMAL);
}
