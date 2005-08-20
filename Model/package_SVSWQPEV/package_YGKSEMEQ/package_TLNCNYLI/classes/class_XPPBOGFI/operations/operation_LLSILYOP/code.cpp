wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");
modelPathTextControl.SetValue(modelPath);
Show(true);
