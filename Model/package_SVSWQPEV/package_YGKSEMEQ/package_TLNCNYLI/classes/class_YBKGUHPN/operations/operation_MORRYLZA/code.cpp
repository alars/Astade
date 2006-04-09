wxConfigBase* theConfig = wxConfigBase::Get();

cancel->SetFocus();

identifyExpression->SetValue(theConfig->Read("TreeView/RegEx/identifyExpression"));
errorLineExpression->SetValue(theConfig->Read("TreeView/RegEx/errorLineExpression"));
errorFileExpression->SetValue(theConfig->Read("TreeView/RegEx/errorFileExpression"));

Show(true);
