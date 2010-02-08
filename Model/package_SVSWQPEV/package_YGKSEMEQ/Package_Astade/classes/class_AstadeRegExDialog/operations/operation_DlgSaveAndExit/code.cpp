wxConfigBase* theConfig = wxConfigBase::Get();

theConfig->Write("TreeView/RegEx/identifyExpression",identifyExpression->GetValue());
theConfig->Write("TreeView/RegEx/errorLineExpression",errorLineExpression->GetValue());
theConfig->Write("TreeView/RegEx/errorFileExpression",errorFileExpression->GetValue());

theConfig->Flush();

Show(false);

