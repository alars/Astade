wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");

bool showIndent = showIndentBox->GetValue();

myEditControl->SetShowIndent(showIndent);

theConfig->Write("CodeEdit/ShowIndent",showIndent);

delete theConfig;