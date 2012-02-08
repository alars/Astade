wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));

bool whitespace = whitespaceBox->GetValue();

myEditControl->SetWhitespace(whitespace);

theConfig->Write(wxS("CodeEdit/Whitespace"), whitespace);

delete theConfig;
