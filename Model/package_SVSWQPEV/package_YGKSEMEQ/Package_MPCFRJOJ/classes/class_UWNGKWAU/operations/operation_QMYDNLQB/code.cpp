wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");

bool lineNumbers = lineNumbersBox->GetValue();

myEditControl->SetLineNumbers(lineNumbers);

theConfig->Write("CodeEdit/LineNumbers",lineNumbers);

delete theConfig;