//~~ void DlgSaveAndExit(wxCommandEvent& event) [AstadeDirDialog] ~~
wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write("Tools/FeatureEdit",featureEditPathTextControl->GetValue());
theConfig->Write("Tools/CodeEdit",codeEditPathTextControl->GetValue());
theConfig->Write("Tools/CodeEdit/editLineOption",editLineOption->GetValue());
theConfig->Write("Tools/OmdViewPath",omdPathTextControl->GetValue());
theConfig->Write("Tools/StatechartViewPath",statechartPathTextControl->GetValue());
theConfig->Write("Tools/Coder",coderPathTextControl->GetValue());
theConfig->Write("Tools/CCoder",ccoderPathTextControl->GetValue());
theConfig->Write("Tools/StatechartCoder",statechartCoderPathTextControl->GetValue());
theConfig->Write("Tools/Make",makePathTextControl->GetValue());
theConfig->Write("TreeView/BuildSound",soundPathTextControl->GetValue());
theConfig->Write("TreeView/TemplatesPath",templatesPathTextControl->GetValue());
theConfig->Write("Tools/SequencesPath",sequencesPathTextControl->GetValue());
theConfig->Write("Tools/UseCasesPath",usecasePathTextControl->GetValue());
theConfig->Write("Tools/DoxWizPath",DoxWizTextControl->GetValue());
theConfig->Write("Tools/CompositeStructureViewPath",compositeStructurePathTextControl->GetValue());


theConfig->Flush();

Show(false);

