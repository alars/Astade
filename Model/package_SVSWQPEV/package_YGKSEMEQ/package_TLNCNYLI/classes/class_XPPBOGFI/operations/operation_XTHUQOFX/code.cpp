wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write("TreeView/Helpfile",helpPathTextControl->GetValue());
theConfig->Write("Tools/FeatureEdit",featureEditPathTextControl->GetValue());
theConfig->Write("Tools/CodeEdit",codeEditPathTextControl->GetValue());
theConfig->Write("Tools/CodeEdit/editLineOption",editLineOption->GetValue());
theConfig->Write("Tools/HtmlBrowser",htmlBrowserPathTextControl->GetValue());
theConfig->Write("Tools/OmdViewPath",omdPathTextControl->GetValue());
theConfig->Write("Tools/StatechartViewPath",statechartPathTextControl->GetValue());
theConfig->Write("Tools/Coder",coderPathTextControl->GetValue());
theConfig->Write("Tools/StatechartCoder",statechartCoderPathTextControl->GetValue());
theConfig->Write("Tools/Make",makePathTextControl->GetValue());
theConfig->Write("TreeView/BuildSound",soundPathTextControl->GetValue());
theConfig->Write("TreeView/TemplatesPath",templatesPathTextControl->GetValue());
theConfig->Write("Tools/SequencesPath",sequencesPathTextControl->GetValue());

theConfig->Flush();

Show(false);

