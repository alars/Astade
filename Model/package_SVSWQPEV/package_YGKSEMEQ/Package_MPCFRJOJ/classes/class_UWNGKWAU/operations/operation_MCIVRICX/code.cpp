wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");
int x,y,w,h;

theConfig->Read("CodeEdit/XPos",&x,-1);
theConfig->Read("CodeEdit/YPos",&y,-1);

theConfig->Read("CodeEdit/XSize",&w,-1);
theConfig->Read("CodeEdit/YSize",&h,-1);

myEditControl->LoadFile(myFileName);

if (initialLine >= 1)
{
    myEditControl->GotoLine(initialLine-1);
    myEditControl->SetFocus();
}

Show(true);
SetMinSize(wxSize(550,300));
SetSize(x,y,w,h);

bool lineNumbers;
theConfig->Read("CodeEdit/LineNumbers",&lineNumbers,false);
myEditControl->SetLineNumbers(lineNumbers);
lineNumbersBox->SetValue(lineNumbers);

bool whitespace;
theConfig->Read("CodeEdit/Whitespace",&whitespace,false);
myEditControl->SetWhitespace(whitespace);
whitespaceBox->SetValue(whitespace);

bool showIndent;
theConfig->Read("CodeEdit/ShowIndent",&showIndent,false);
myEditControl->SetShowIndent(showIndent);
showIndentBox->SetValue(showIndent);

delete theConfig;