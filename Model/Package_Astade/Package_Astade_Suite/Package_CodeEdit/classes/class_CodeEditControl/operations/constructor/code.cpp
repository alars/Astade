//~~ CodeEditControl(wxWindow * parent, wxWindowID id, const wxPoint & pos = wxDefaultPosition, const wxSize & size = wxDefaultSize, long style = 0) [CodeEditControl] ~~
m_filename = wxEmptyString;

m_LineNrID = 0;
m_DividerID = 1;
m_FoldingID = 2;

// initialize language
m_language = NULL;

// default font for all styles
SetViewEOL (g_CommonPrefs.displayEOLEnable);
SetIndentationGuides (g_CommonPrefs.indentGuideEnable);
SetEdgeMode (g_CommonPrefs.longLineOnEnable?
             wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
SetViewWhiteSpace (g_CommonPrefs.whiteSpaceEnable?
                   wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
SetOvertype (g_CommonPrefs.overTypeInitial);
SetReadOnly (g_CommonPrefs.readOnlyInitial);
SetWrapMode (g_CommonPrefs.wrapModeInitial?
             wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);
wxFont font (10, wxMODERN, wxNORMAL, wxNORMAL);
StyleSetFont (wxSTC_STYLE_DEFAULT, font);
StyleSetForeground (wxSTC_STYLE_DEFAULT, *wxBLACK);
StyleSetBackground (wxSTC_STYLE_DEFAULT, *wxWHITE);
StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (wxS("DARK GREY")));
StyleSetBackground (wxSTC_STYLE_LINENUMBER, *wxWHITE);
StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour (wxS("DARK GREY")));
InitializePrefs (DEFAULT_LANGUAGE);

// set visibility
SetVisiblePolicy (wxSTC_VISIBLE_STRICT|wxSTC_VISIBLE_SLOP, 1);
SetXCaretPolicy (wxSTC_CARET_EVEN|wxSTC_VISIBLE_STRICT|wxSTC_CARET_SLOP, 1);
SetYCaretPolicy (wxSTC_CARET_EVEN|wxSTC_VISIBLE_STRICT|wxSTC_CARET_SLOP, 1);

// markers
MarkerDefine (wxSTC_MARKNUM_FOLDER,        wxSTC_MARK_DOTDOTDOT, wxS("BLACK"), wxS("BLACK"));
MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN, wxS("BLACK"), wxS("BLACK"));
MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_EMPTY,     wxS("BLACK"), wxS("BLACK"));
MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_DOTDOTDOT, wxS("BLACK"), wxS("WHITE"));
MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN, wxS("BLACK"), wxS("WHITE"));
MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY,     wxS("BLACK"), wxS("BLACK"));
MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_EMPTY,     wxS("BLACK"), wxS("BLACK"));

// miscelaneous
m_LineNrMargin = TextWidth (wxSTC_STYLE_LINENUMBER, wxS("_999999"));
m_FoldingMargin = 16;
CmdKeyClear (wxSTC_KEY_TAB, 0); // this is done by the menu accelerator key
SetLayoutCache (wxSTC_CACHE_PAGE);
