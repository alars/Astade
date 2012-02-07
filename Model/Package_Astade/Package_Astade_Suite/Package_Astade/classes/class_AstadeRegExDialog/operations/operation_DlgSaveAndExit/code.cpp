//~~ void DlgSaveAndExit(wxCommandEvent& event) [AstadeRegExDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write(wxS("TreeView/RegEx/identifyExpression"), identifyExpression->GetValue());
theConfig->Write(wxS("TreeView/RegEx/errorLineExpression"), errorLineExpression->GetValue());
theConfig->Write(wxS("TreeView/RegEx/errorFileExpression"), errorFileExpression->GetValue());

theConfig->Flush();

Show(false);

