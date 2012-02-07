//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeConfiguration] ~~

aPopUp.Append(ID_FEATURES, wxS("features"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET | COPY_SOURCE);
aPopUp.AppendSeparator();
AppendMakeTargets(aPopUp, !makeIsRunning);

aPopUp.AppendSeparator();
aPopUp.Append(ID_COPYMAKEFILE, wxS("copy Makefile"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
{
	aPopUp.Append(ID_RENAMEELEMENT, wxS("Rename configuration folder"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.AppendSeparator();
}


aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
