//~~ void DlgSaveAndExit(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write(wxS("Tools/FeatureEdit"), featureEditPathTextControl->GetValue());
theConfig->Write(wxS("Tools/CodeEdit"), codeEditPathTextControl->GetValue());
theConfig->Write(wxS("Tools/CodeEdit/editLineOption"), editLineOption->GetValue());
theConfig->Write(wxS("Tools/OmdViewPath"), omdPathTextControl->GetValue());
theConfig->Write(wxS("Tools/StatechartViewPath"), statechartPathTextControl->GetValue());
theConfig->Write(wxS("Tools/Coder"), coderPathTextControl->GetValue());
theConfig->Write(wxS("Tools/CCoder"), ccoderPathTextControl->GetValue());
theConfig->Write(wxS("Tools/PythonCoder"), pythoncoderPathTextControl->GetValue());
theConfig->Write(wxS("Tools/StatechartCoder"), statechartCoderPathTextControl->GetValue());
theConfig->Write(wxS("Tools/Make"), makePathTextControl->GetValue());
theConfig->Write(wxS("TreeView/BuildSound"), soundPathTextControl->GetValue());
theConfig->Write(wxS("TreeView/TemplatesPath"), templatesPathTextControl->GetValue());
theConfig->Write(wxS("Tools/SequencesPath"), sequencesPathTextControl->GetValue());
theConfig->Write(wxS("Tools/UseCasesPath"), usecasePathTextControl->GetValue());
theConfig->Write(wxS("Tools/DoxWizPath"), DoxWizTextControl->GetValue());
theConfig->Write(wxS("Tools/CompositeStructureViewPath"), compositeStructurePathTextControl->GetValue());

theConfig->Flush();

Show(false);
