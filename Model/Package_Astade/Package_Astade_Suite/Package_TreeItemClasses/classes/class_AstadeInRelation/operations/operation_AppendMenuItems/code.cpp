//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeInRelation] ~~

aPopUp.Append(ID_JUMPORIG, wxS("jump to origin"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_CUT, wxS("cut"), wxEmptyString, wxITEM_NORMAL);

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename element file"), wxEmptyString, wxITEM_NORMAL);
}
