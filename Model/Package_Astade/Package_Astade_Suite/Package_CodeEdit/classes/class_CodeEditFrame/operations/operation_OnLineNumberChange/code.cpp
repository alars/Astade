wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));

bool lineNumbers = lineNumbersBox->GetValue();

myEditControl->SetLineNumbers(lineNumbers);

theConfig->Write(wxS("CodeEdit/LineNumbers"), lineNumbers);

delete theConfig;
