wxConfigBase* theConfig = wxConfigBase::Get();

modelPathTextControl->SetValue(theConfig->Read("TreeView/ModelPath"));
helpPathTextControl->SetValue(theConfig->Read("TreeView/Helpfile"));
featureEditPathTextControl->SetValue(theConfig->Read("Tools/FeatureEdit"));
codeEditPathTextControl->SetValue(theConfig->Read("Tools/CodeEdit"));
omdPathTextControl->SetValue(theConfig->Read("Tools/OmdViewPath"));
statechartPathTextControl->SetValue(theConfig->Read("Tools/StatechartViewPath"));
coderPathTextControl->SetValue(theConfig->Read("Tools/Coder"));
statechartCoderPathTextControl->SetValue(theConfig->Read("Tools/StatechartCoder"));
makePathTextControl->SetValue(theConfig->Read("Tools/Make"));
templatesPathTextControl->SetValue(theConfig->Read("TreeView/TemplatesPath"));

Show(true);
