wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write("TreeView/ModelPath",modelPathTextControl.GetValue());
theConfig->Write("TreeView/Helpfile",helpPathTextControl.GetValue());

theConfig->Flush();

Show(false);

