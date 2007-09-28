wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");

bool whitespace = whitespaceBox->GetValue();

myEditControl->SetWhitespace(whitespace);

theConfig->Write("CodeEdit/Whitespace",whitespace);

delete theConfig;