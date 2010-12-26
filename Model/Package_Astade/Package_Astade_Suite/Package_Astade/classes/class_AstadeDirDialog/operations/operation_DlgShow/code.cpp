//~~ void DlgShow() [AstadeDirDialog] ~~
wxConfigBase* theConfig = wxConfigBase::Get();

cancel->SetFocus();

featureEditPathTextControl->SetValue(theConfig->Read("Tools/FeatureEdit"));
codeEditPathTextControl->SetValue(theConfig->Read("Tools/CodeEdit"));
editLineOption->SetValue(theConfig->Read("Tools/CodeEdit/editLineOption"));
omdPathTextControl->SetValue(theConfig->Read("Tools/OmdViewPath"));
statechartPathTextControl->SetValue(theConfig->Read("Tools/StatechartViewPath"));
compositeStructurePathTextControl->SetValue(theConfig->Read("Tools/CompositeStructureViewPath"));
coderPathTextControl->SetValue(theConfig->Read("Tools/Coder"));
ccoderPathTextControl->SetValue(theConfig->Read("Tools/CCoder"));
statechartCoderPathTextControl->SetValue(theConfig->Read("Tools/StatechartCoder"));
makePathTextControl->SetValue(theConfig->Read("Tools/Make"));
soundPathTextControl->SetValue(theConfig->Read("TreeView/BuildSound"));
templatesPathTextControl->SetValue(theConfig->Read("TreeView/TemplatesPath"));
sequencesPathTextControl->SetValue(theConfig->Read("Tools/SequencesPath"));
usecasePathTextControl->SetValue(theConfig->Read("Tools/UseCasesPath"));
DoxWizTextControl->SetValue(theConfig->Read("Tools/DoxWizPath"));

Show(true);
