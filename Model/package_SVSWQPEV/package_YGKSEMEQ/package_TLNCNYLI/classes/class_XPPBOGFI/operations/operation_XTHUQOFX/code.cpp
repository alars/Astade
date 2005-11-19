wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write("TreeView/ModelPath",modelPathTextControl->GetValue());
theConfig->Write("TreeView/Helpfile",helpPathTextControl->GetValue());
theConfig->Write("Tools/FeatureEdit",featureEditPathTextControl->GetValue());
theConfig->Write("Tools/CodeEdit",codeEditPathTextControl->GetValue());
theConfig->Write("Tools/OmdViewPath",omdPathTextControl->GetValue());
theConfig->Write("Tools/StatechartViewPath",statechartPathTextControl->GetValue());
theConfig->Write("Tools/Coder",coderPathTextControl->GetValue());
theConfig->Write("Tools/Make",makePathTextControl->GetValue());
theConfig->Write("TreeView/TemplatesPath",templatesPathTextControl->GetValue());

theConfig->Flush();

Show(false);

