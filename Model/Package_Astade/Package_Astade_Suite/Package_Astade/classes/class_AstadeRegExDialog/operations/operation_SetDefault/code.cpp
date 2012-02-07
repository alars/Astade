//~~ void SetDefault(wxCommandEvent& event) [AstadeRegExDialog] ~~

identifyExpression->SetValue(wxS("error:|warning:"));
errorFileExpression->SetValue(wxS("(^[^:]+|^[A-Z]:[^:]+):"));
errorLineExpression->SetValue(wxS(":([0-9]+):"));
