aPopUp.Append(ID_FEATURES, "features", wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET | COPY_SOURCE);
aPopUp.AppendSeparator();
AppendMakeTargets(aPopUp,!makeIsRunning);

aPopUp.AppendSeparator();
aPopUp.Append(ID_COPYMAKEFILE, "copy Makefile", wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
	aPopUp.Append(ID_RENAMEELEMENT,"Rename configuration folder",wxEmptyString, wxITEM_NORMAL);

aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);
