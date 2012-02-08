wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));
int x,y,w,h;

theConfig->Read(wxS("CodeEdit/XPos"), &x, -1);
theConfig->Read(wxS("CodeEdit/YPos"), &y, -1);

theConfig->Read(wxS("CodeEdit/XSize"), &w, -1);
theConfig->Read(wxS("CodeEdit/YSize"), &h, -1);

myEditControl->LoadFile(myFileName);

if (initialLine >= 1)
{
    myEditControl->GotoLine(initialLine-1);
    myEditControl->SetFocus();
}

Show(true);
SetMinSize(wxSize(750,300));
SetSize(x,y,w,h);

bool lineNumbers;
theConfig->Read(wxS("CodeEdit/LineNumbers"), &lineNumbers, false);
myEditControl->SetLineNumbers(lineNumbers);
lineNumbersBox->SetValue(lineNumbers);

bool whitespace;
theConfig->Read(wxS("CodeEdit/Whitespace"), &whitespace, false);
myEditControl->SetWhitespace(whitespace);
whitespaceBox->SetValue(whitespace);

bool showIndent;
theConfig->Read(wxS("CodeEdit/ShowIndent"), &showIndent, false);
myEditControl->SetShowIndent(showIndent);
showIndentBox->SetValue(showIndent);

delete theConfig;
