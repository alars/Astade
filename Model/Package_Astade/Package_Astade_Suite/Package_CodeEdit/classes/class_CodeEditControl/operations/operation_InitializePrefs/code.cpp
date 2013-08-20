//~~ bool InitializePrefs(const wxString & name) [CodeEditControl] ~~
// initialize styles
StyleClearAll();
LanguageInfo const* curInfo = NULL;

// determine language
bool found = false;
int languageNr;
for (languageNr = 0; languageNr < g_LanguagePrefsSize; languageNr++) {
    curInfo = &g_LanguagePrefs [languageNr];
    if (curInfo->name == name) {
        found = true;
        break;
    }
}
if (!found)
	return false;

// set lexer and language
SetLexer (curInfo->lexer);
m_language = curInfo;

// set margin for line numbers
SetMarginType (m_LineNrID, wxSTC_MARGIN_NUMBER);
StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (wxS("DARK GREY")));
StyleSetBackground (wxSTC_STYLE_LINENUMBER, *wxWHITE);
SetMarginWidth (m_LineNrID, 0); // start out not visible

// default fonts for all styles!
int Nr;
for (Nr = 0; Nr < wxSTC_STYLE_LASTPREDEFINED; Nr++) {
    wxFont font (10, wxMODERN, wxNORMAL, wxNORMAL);
    StyleSetFont (Nr, font);
}

// set common styles
StyleSetForeground (wxSTC_STYLE_DEFAULT, wxColour (wxS("DARK GREY")));
StyleSetForeground (wxSTC_STYLE_INDENTGUIDE, wxColour (wxS("DARK GREY")));

// initialize settings
if (g_CommonPrefs.syntaxEnable) {
    int keywordnr = 0;
    for (Nr = 0; Nr < STYLE_TYPES_COUNT; Nr++) {
        if (curInfo->styles[Nr].type == -1)
			continue;
        const StyleInfo &curType = g_StylePrefs [curInfo->styles[Nr].type];
        wxFont font (curType.fontsize, wxMODERN, wxNORMAL, wxNORMAL, false,
                     curType.fontname);
        StyleSetFont (Nr, font);
        if (!curType.foreground.empty()) {
            StyleSetForeground (Nr, wxColour (curType.foreground));
        }
        if (!curType.background.empty()) {
            StyleSetBackground (Nr, wxColour (curType.background));
        }
        StyleSetBold (Nr, (curType.fontstyle & mySTC_STYLE_BOLD) > 0);
        StyleSetItalic (Nr, (curType.fontstyle & mySTC_STYLE_ITALIC) > 0);
        StyleSetUnderline (Nr, (curType.fontstyle & mySTC_STYLE_UNDERL) > 0);
        StyleSetVisible (Nr, (curType.fontstyle & mySTC_STYLE_HIDDEN) == 0);
        StyleSetCase (Nr, curType.lettercase);
        const wxString pwords = curInfo->styles[Nr].words;
        if (!pwords.empty()) {
            SetKeyWords (keywordnr, pwords);
            keywordnr += 1;
        }
    }
}

// set margin as unused
SetMarginType (m_DividerID, wxSTC_MARGIN_SYMBOL);
SetMarginWidth (m_DividerID, 0);
SetMarginSensitive (m_DividerID, false);

// folding
SetMarginType (m_FoldingID, wxSTC_MARGIN_SYMBOL);
SetMarginMask (m_FoldingID, wxSTC_MASK_FOLDERS);
StyleSetBackground (m_FoldingID, *wxWHITE);
SetMarginWidth (m_FoldingID, 0);
SetMarginSensitive (m_FoldingID, false);
if (g_CommonPrefs.foldEnable) {
    SetMarginWidth (m_FoldingID, curInfo->folds != 0? m_FoldingMargin: 0);
    SetMarginSensitive (m_FoldingID, curInfo->folds != 0);
    SetProperty (wxS("fold"), curInfo->folds != 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.comment"),
                 (curInfo->folds & mySTC_FOLD_COMMENT) > 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.compact"),
                 (curInfo->folds & mySTC_FOLD_COMPACT) > 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.preprocessor"),
                 (curInfo->folds & mySTC_FOLD_PREPROC) > 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.html"),
                 (curInfo->folds & mySTC_FOLD_HTML) > 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.html.preprocessor"),
                 (curInfo->folds & mySTC_FOLD_HTMLPREP) > 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.comment.python"),
                 (curInfo->folds & mySTC_FOLD_COMMENTPY) > 0 ? wxS("1"): wxS("0"));
    SetProperty (wxS("fold.quotes.python"),
                 (curInfo->folds & mySTC_FOLD_QUOTESPY) > 0 ? wxS("1"): wxS("0"));
}
SetFoldFlags (wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED |
              wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);

// set spaces and indention
SetTabWidth (4);
SetUseTabs (false);
SetTabIndents (true);
SetBackSpaceUnIndents (true);
SetIndent (g_CommonPrefs.indentEnable? 4: 0);

// others
SetViewEOL (g_CommonPrefs.displayEOLEnable);
SetIndentationGuides (g_CommonPrefs.indentGuideEnable);
SetEdgeColumn (80);
SetEdgeMode (g_CommonPrefs.longLineOnEnable? wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
SetViewWhiteSpace (g_CommonPrefs.whiteSpaceEnable?
                   wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
SetOvertype (g_CommonPrefs.overTypeInitial);
SetReadOnly (g_CommonPrefs.readOnlyInitial);
SetWrapMode (g_CommonPrefs.wrapModeInitial?
             wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);

//change the color for C keywords
//StyleSetForeground (wxSTC_C_STRING,            wxColour(200,0,0));
//StyleSetForeground (wxSTC_C_PREPROCESSOR,      wxColour(165,105,0));
//StyleSetForeground (wxSTC_C_IDENTIFIER,        wxColour(40,0,60));
//StyleSetForeground (wxSTC_C_NUMBER,            wxColour(0,150,0));
StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(230,0,0));
//StyleSetForeground (wxSTC_C_WORD,              wxColour(0,0,150));
//StyleSetForeground (wxSTC_C_WORD2,             wxColour(0,150,0));
//StyleSetForeground (wxSTC_C_COMMENT,           wxColour(150,150,150));
//StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(150,150,150));
//StyleSetForeground (wxSTC_C_COMMENTDOC,        wxColour(150,150,150));
//StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, wxColour(0,0,200));
//StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0,0,200));
//StyleSetBold(wxSTC_C_WORD, true);
//StyleSetBold(wxSTC_C_WORD2, true);
//StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

return true;
