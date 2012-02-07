//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeParameter] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();
aPopUp.Append(ID_UP, wxS("up"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_DOWN, wxS("down"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename element file"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);

if (!ourTree->GetPrevSibling(GetId()).IsOk())
	aPopUp.Enable(ID_UP, false);

if (!ourTree->GetNextSibling(GetId()).IsOk())
	aPopUp.Enable(ID_DOWN, false);
