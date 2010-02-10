AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDRELATION,"start relation to ...",wxEmptyString, wxITEM_NORMAL);
if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.AppendSeparator();
	aPopUp.Append(ID_RENAMEELEMENTS,"Rename all relations",wxEmptyString, wxITEM_NORMAL);
}
