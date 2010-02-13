aPopUp.Append(ID_JUMPORIG,"jump to origin",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_RENAMEELEMENT,"Rename element file",wxEmptyString, wxITEM_NORMAL);
}
