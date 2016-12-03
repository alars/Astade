//~~ void DlgShow() [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

cancel->SetFocus();

featureEditPathTextControl->SetValue(theConfig->Read(wxS("Tools/FeatureEdit")));
codeEditPathTextControl->SetValue(theConfig->Read(wxS("Tools/CodeEdit")));
editLineOption->SetValue(theConfig->Read(wxS("Tools/CodeEdit/editLineOption")));
omdPathTextControl->SetValue(theConfig->Read(wxS("Tools/OmdViewPath")));
statechartPathTextControl->SetValue(theConfig->Read(wxS("Tools/StatechartViewPath")));
compositeStructurePathTextControl->SetValue(theConfig->Read(wxS("Tools/CompositeStructureViewPath")));
coderPathTextControl->SetValue(theConfig->Read(wxS("Tools/Coder")));
ccoderPathTextControl->SetValue(theConfig->Read(wxS("Tools/CCoder")));
pythoncoderPathTextControl->SetValue(theConfig->Read(wxS("Tools/PythonCoder")));
statechartCoderPathTextControl->SetValue(theConfig->Read(wxS("Tools/StatechartCoder")));
makePathTextControl->SetValue(theConfig->Read(wxS("Tools/Make")));
soundPathTextControl->SetValue(theConfig->Read(wxS("TreeView/BuildSound")));
templatesPathTextControl->SetValue(theConfig->Read(wxS("TreeView/TemplatesPath")));
sequencesPathTextControl->SetValue(theConfig->Read(wxS("Tools/SequencesPath")));
usecasePathTextControl->SetValue(theConfig->Read(wxS("Tools/UseCasesPath")));
DoxWizTextControl->SetValue(theConfig->Read(wxS("Tools/DoxWizPath")));

Show(true);
