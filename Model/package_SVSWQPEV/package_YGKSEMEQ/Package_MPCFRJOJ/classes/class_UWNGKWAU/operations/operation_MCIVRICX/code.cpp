wxConfigBase::Set(new wxFileConfig("Astade.ini"));

myEditControl->LoadFile (myFileName);
myEditControl->SetWrapMode(wxSCI_WRAP_NONE);
myEditControl->SetLexer(wxSCI_LEX_CPP);

myEditControl->SetUseVerticalScrollBar (false);
myEditControl->SetUseHorizontalScrollBar (false);


//      bold                    turns on bold
//      italic                  turns on italics
//      fore:[name or #RRGGBB]  sets the foreground colour
//      back:[name or #RRGGBB]  sets the background colour
//      face:[facename]         sets the font face name to use
//      size:[num]              sets the font size in points
//      eol                     turns on eol filling
//      underline               turns on underlining

myEditControl->StyleSetSpec(wxSCI_C_DEFAULT,				"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_COMMENT,				"face:courier new,fore:#5eac7a");
myEditControl->StyleSetSpec(wxSCI_C_COMMENTLINE,			"face:courier new,fore:#5eac7a");
myEditControl->StyleSetSpec(wxSCI_C_COMMENTDOC,				"face:courier new,fore:#5eac7a");
myEditControl->StyleSetSpec(wxSCI_C_NUMBER,					"face:courier new,fore:blue");
myEditControl->StyleSetSpec(wxSCI_C_WORD,					"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_STRING,					"face:courier new,fore:magenta");
myEditControl->StyleSetSpec(wxSCI_C_CHARACTER,				"face:courier new,fore:blue");
myEditControl->StyleSetSpec(wxSCI_C_UUID,					"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_PREPROCESSOR,			"face:courier new,fore:blue");
myEditControl->StyleSetSpec(wxSCI_C_OPERATOR,				"face:courier new,fore:black,bold");
myEditControl->StyleSetSpec(wxSCI_C_IDENTIFIER,				"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_STRINGEOL,				"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_VERBATIM,				"face:courier new,fore:red");
myEditControl->StyleSetSpec(wxSCI_C_REGEX,					"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_COMMENTLINEDOC,			"face:courier new,fore:red");
myEditControl->StyleSetSpec(wxSCI_C_WORD2,					"face:courier new,fore:black");
myEditControl->StyleSetSpec(wxSCI_C_COMMENTDOCKEYWORD,		"face:courier new,fore:red");
myEditControl->StyleSetSpec(wxSCI_C_COMMENTDOCKEYWORDERROR,	"face:courier new,fore:red");
myEditControl->StyleSetSpec(wxSCI_C_GLOBALCLASS,			"face:courier new,fore:black");


wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");
int x,y,w,h;

theConfig->Read("CodeEdit/XPos",&x,-1);
theConfig->Read("CodeEdit/YPos",&y,-1);

theConfig->Read("CodeEdit/XSize",&w,-1);
theConfig->Read("CodeEdit/YSize",&h,-1);

SetSize(x,y,w,h);
delete theConfig;

Show(true);