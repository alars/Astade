wxConfigBase* theConfig = wxConfigBase::Get();

cancel->SetFocus();

helpPathTextControl->SetValue(theConfig->Read("TreeView/Helpfile"));
featureEditPathTextControl->SetValue(theConfig->Read("Tools/FeatureEdit"));
codeEditPathTextControl->SetValue(theConfig->Read("Tools/CodeEdit"));
editLineOption->SetValue(theConfig->Read("Tools/CodeEdit/editLineOption"));
htmlBrowserPathTextControl->SetValue(theConfig->Read("Tools/HtmlBrowser"));
omdPathTextControl->SetValue(theConfig->Read("Tools/OmdViewPath"));
statechartPathTextControl->SetValue(theConfig->Read("Tools/StatechartViewPath"));
coderPathTextControl->SetValue(theConfig->Read("Tools/Coder"));
statechartCoderPathTextControl->SetValue(theConfig->Read("Tools/StatechartCoder"));
makePathTextControl->SetValue(theConfig->Read("Tools/Make"));
soundPathTextControl->SetValue(theConfig->Read("TreeView/BuildSound"));
templatesPathTextControl->SetValue(theConfig->Read("TreeView/TemplatesPath"));
sequencesPathTextControl->SetValue(theConfig->Read("Tools/SequencesPath"));

Show(true);
