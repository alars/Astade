//~~ void DlgShow() [AstadeRegExDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

cancel->SetFocus();

identifyExpression->SetValue(theConfig->Read(wxS("TreeView/RegEx/identifyExpression")));
errorLineExpression->SetValue(theConfig->Read(wxS("TreeView/RegEx/errorLineExpression")));
errorFileExpression->SetValue(theConfig->Read(wxS("TreeView/RegEx/errorFileExpression")));

Show(true);
