//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeRelation] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_JUMPDEST, wxS("jump to destination"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename element file"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}

aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
