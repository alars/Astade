wxConfigBase* theConfig = wxConfigBase::Get();

wxString modelPath = modelPathTextControl.GetValue();
theConfig->Write("TreeView/ModelPath",modelPath);

Show(false);

