#include "CodeEditControl.h"

//============================================================================
// declarations
//============================================================================

#ifndef wxS
#  define wxS wxT
#endif

//----------------------------------------------------------------------------
//! language types
const CommonInfo g_CommonPrefs = {
    // editor functionality prefs
    true,  // syntaxEnable
    true,  // foldEnable
    true,  // indentEnable
    // display defaults prefs
    false, // overTypeInitial
    false, // readOnlyInitial
    false,  // wrapModeInitial
    false, // displayEOLEnable
    false, // IndentGuideEnable
    true,  // lineNumberEnable
    false, // longLineOnEnable
    false, // whiteSpaceEnable
};

//----------------------------------------------------------------------------
// keywordlists
// C++
const wxString CppWordlist1 =
    wxS("asm auto bool break case catch char class const const_cast ")
    wxS("continue default delete do double dynamic_cast else enum explicit ")
    wxS("export extern false float for friend goto if inline int long ")
    wxS("mutable namespace new operator private protected public register ")
    wxS("reinterpret_cast return short signed sizeof static static_cast ")
    wxS("struct switch template this throw true try typedef typeid ")
    wxS("typename union unsigned using virtual void volatile wchar_t ")
    wxS("while");
const wxString CppWordlist2 =
    wxS("file");
const wxString CppWordlist3 =
    wxS("a addindex addtogroup anchor arg attention author b brief bug c ")
    wxS("class code date def defgroup deprecated dontinclude e em endcode ")
    wxS("endhtmlonly endif endlatexonly endlink endverbatim enum example ")
    wxS("exception f$ f[ f] file fn hideinitializer htmlinclude ")
    wxS("htmlonly if image include ingroup internal invariant interface ")
    wxS("latexonly li line link mainpage name namespace nosubgrouping note ")
    wxS("overload p page par param post pre ref relates remarks return ")
    wxS("retval sa section see showinitializer since skip skipline struct ")
    wxS("subsection test throw todo typedef union until var verbatim ")
    wxS("verbinclude version warning weakgroup $ @ \"\" & < > # { }");

// Python
const wxString PythonWordlist1 =
    wxS("and assert break class continue def del elif else except exec ")
    wxS("finally for from global if import in is lambda None not or pass ")
    wxS("print raise return try while yield");
const wxString PythonWordlist2 =
    wxS("ACCELERATORS ALT AUTO3STATE AUTOCHECKBOX AUTORADIOBUTTON BEGIN ")
    wxS("BITMAP BLOCK BUTTON CAPTION CHARACTERISTICS CHECKBOX CLASS ")
    wxS("COMBOBOX CONTROL CTEXT CURSOR DEFPUSHBUTTON DIALOG DIALOGEX ")
    wxS("DISCARDABLE EDITTEXT END EXSTYLE FONT GROUPBOX ICON LANGUAGE ")
    wxS("LISTBOX LTEXT MENU MENUEX MENUITEM MESSAGETABLE POPUP PUSHBUTTON ")
    wxS("RADIOBUTTON RCDATA RTEXT SCROLLBAR SEPARATOR SHIFT STATE3 ")
    wxS("STRINGTABLE STYLE TEXTINCLUDE VALUE VERSION VERSIONINFO VIRTKEY");


//----------------------------------------------------------------------------
//! languages
const LanguageInfo g_LanguagePrefs [] = {
    // C++
    {wxS("C++"),
     wxS("*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma"),
     wxSTC_LEX_CPP,
     {{mySTC_TYPE_DEFAULT, wxEmptyString},
      {mySTC_TYPE_COMMENT, wxEmptyString},
      {mySTC_TYPE_COMMENT_LINE, wxEmptyString},
      {mySTC_TYPE_COMMENT_DOC, wxEmptyString},
      {mySTC_TYPE_NUMBER, wxEmptyString},
      {mySTC_TYPE_WORD1, CppWordlist1}, // KEYWORDS
      {mySTC_TYPE_STRING, wxEmptyString},
      {mySTC_TYPE_CHARACTER, wxEmptyString},
      {mySTC_TYPE_UUID, wxEmptyString},
      {mySTC_TYPE_PREPROCESSOR, wxEmptyString},
      {mySTC_TYPE_OPERATOR, wxEmptyString},
      {mySTC_TYPE_IDENTIFIER, wxEmptyString},
      {mySTC_TYPE_STRING_EOL, wxEmptyString},
      {mySTC_TYPE_DEFAULT, wxEmptyString}, // VERBATIM
      {mySTC_TYPE_REGEX, wxEmptyString},
      {mySTC_TYPE_COMMENT_SPECIAL, wxEmptyString}, // DOXY
      {mySTC_TYPE_WORD2, CppWordlist2}, // EXTRA WORDS
      {mySTC_TYPE_WORD3, CppWordlist3}, // DOXY KEYWORDS
      {mySTC_TYPE_ERROR, wxEmptyString}, // KEYWORDS ERROR
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString}},
     mySTC_FOLD_COMMENT | mySTC_FOLD_COMPACT | mySTC_FOLD_PREPROC},
    // Python
    {wxS("Python"),
     wxS("*.py;*.pyw"),
     wxSTC_LEX_PYTHON,
     {{mySTC_TYPE_DEFAULT, wxEmptyString},
      {mySTC_TYPE_COMMENT_LINE, wxEmptyString},
      {mySTC_TYPE_NUMBER, wxEmptyString},
      {mySTC_TYPE_STRING, wxEmptyString},
      {mySTC_TYPE_CHARACTER, wxEmptyString},
      {mySTC_TYPE_WORD1, PythonWordlist1}, // KEYWORDS
      {mySTC_TYPE_DEFAULT, wxEmptyString}, // TRIPLE
      {mySTC_TYPE_DEFAULT, wxEmptyString}, // TRIPLEDOUBLE
      {mySTC_TYPE_DEFAULT, wxEmptyString}, // CLASSNAME
      {mySTC_TYPE_DEFAULT, PythonWordlist2}, // DEFNAME
      {mySTC_TYPE_OPERATOR, wxEmptyString},
      {mySTC_TYPE_IDENTIFIER, wxEmptyString},
      {mySTC_TYPE_DEFAULT, wxEmptyString}, // COMMENT_BLOCK
      {mySTC_TYPE_STRING_EOL, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString}},
     mySTC_FOLD_COMMENTPY | mySTC_FOLD_QUOTESPY},
    // * (any)
    {wxS("any"),
     wxS("*.*"),
     wxSTC_LEX_PROPERTIES,
     {{mySTC_TYPE_DEFAULT, wxEmptyString},
      {mySTC_TYPE_DEFAULT, wxEmptyString},
      {mySTC_TYPE_DEFAULT, wxEmptyString},
      {mySTC_TYPE_DEFAULT, wxEmptyString},
      {mySTC_TYPE_DEFAULT, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString},
      {-1, wxEmptyString}},
     0},
    };

const int g_LanguagePrefsSize = WXSIZEOF(g_LanguagePrefs);

//----------------------------------------------------------------------------
//! style types
const StyleInfo g_StylePrefs [] = {
    // mySTC_TYPE_DEFAULT
    {wxS("Default"),
     wxS("BLACK"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_WORD1
    {wxS("Keyword1"),
     wxS("BLUE"), wxS("WHITE"),
     wxEmptyString, 10, mySTC_STYLE_BOLD, 0},

    // mySTC_TYPE_WORD2
    {wxS("Keyword2"),
     wxS("DARK BLUE"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_WORD3
    {wxS("Keyword3"),
     wxS("CORNFLOWER BLUE"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_WORD4
    {wxS("Keyword4"),
     wxS("CYAN"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_WORD5
    {wxS("Keyword5"),
     wxS("DARK GREY"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_WORD6
    {wxS("Keyword6"),
     wxS("GREY"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_COMMENT
    {wxS("Comment"),
     wxS("FOREST GREEN"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_COMMENT_DOC
    {wxS("Comment (Doc)"),
     wxS("FOREST GREEN"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_COMMENT_LINE
    {wxS("Comment line"),
     wxS("FOREST GREEN"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_COMMENT_SPECIAL
    {wxS("Special comment"),
     wxS("FOREST GREEN"), wxS("WHITE"),
     wxEmptyString, 10, mySTC_STYLE_ITALIC, 0},

    // mySTC_TYPE_CHARACTER
    {wxS("Character"),
     wxS("KHAKI"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_CHARACTER_EOL
    {wxS("Character (EOL)"),
     wxS("KHAKI"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_STRING
    {wxS("String"),
     wxS("BROWN"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_STRING_EOL
    {wxS("String (EOL)"),
     wxS("BROWN"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_DELIMITER
    {wxS("Delimiter"),
     wxS("ORANGE"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_PUNCTUATION
    {wxS("Punctuation"),
     wxS("ORANGE"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_OPERATOR
    {wxS("Operator"),
     wxS("BLACK"), wxS("WHITE"),
     wxEmptyString, 10, mySTC_STYLE_BOLD, 0},

    // mySTC_TYPE_BRACE
    {wxS("Label"),
     wxS("VIOLET"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_COMMAND
    {wxS("Command"),
     wxS("BLUE"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_IDENTIFIER
    {wxS("Identifier"),
     wxS("BLACK"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_LABEL
    {wxS("Label"),
     wxS("VIOLET"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_NUMBER
    {wxS("Number"),
     wxS("SIENNA"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_PARAMETER
    {wxS("Parameter"),
     wxS("VIOLET"), wxS("WHITE"),
     wxEmptyString, 10, mySTC_STYLE_ITALIC, 0},

    // mySTC_TYPE_REGEX
    {wxS("Regular expression"),
     wxS("ORCHID"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_UUID
    {wxS("UUID"),
     wxS("ORCHID"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_VALUE
    {wxS("Value"),
     wxS("ORCHID"), wxS("WHITE"),
     wxEmptyString, 10, mySTC_STYLE_ITALIC, 0},

    // mySTC_TYPE_PREPROCESSOR
    {wxS("Preprocessor"),
     wxS("GREY"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_SCRIPT
    {wxS("Script"),
     wxS("DARK GREY"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_ERROR
    {wxS("Error"),
     wxS("RED"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0},

    // mySTC_TYPE_UNDEFINED
    {wxS("Undefined"),
     wxS("ORANGE"), wxS("WHITE"),
     wxEmptyString, 10, 0, 0}

    };

const int g_StylePrefsSize = WXSIZEOF(g_StylePrefs);
