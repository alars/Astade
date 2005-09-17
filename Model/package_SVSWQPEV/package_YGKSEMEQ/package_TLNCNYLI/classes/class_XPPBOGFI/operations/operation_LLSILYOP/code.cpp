wxConfigBase* theConfig = wxConfigBase::Get();

modelPathTextControl.SetValue(theConfig->Read("TreeView/ModelPath"));
helpPathTextControl.SetValue(theConfig->Read("TreeView/Helpfile"));

Show(true);
