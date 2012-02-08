wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));

bool showIndent = showIndentBox->GetValue();

myEditControl->SetShowIndent(showIndent);

theConfig->Write(wxS("CodeEdit/ShowIndent"), showIndent);

delete theConfig;
