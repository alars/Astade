BEGIN_EVENT_TABLE (CodeEditControl, wxStyledTextCtrl)
    // common
    EVT_SIZE (                         CodeEditControl::OnSize)
    EVT_KEY_DOWN (                     CodeEditControl::OnKey)
    // edit
    EVT_MENU (wxID_CLEAR,              CodeEditControl::OnEditClear)
    EVT_MENU (wxID_CUT,                CodeEditControl::OnEditCut)
    EVT_MENU (wxID_COPY,               CodeEditControl::OnEditCopy)
    EVT_MENU (wxID_PASTE,              CodeEditControl::OnEditPaste)
    EVT_MENU (wxID_SELECTALL,          CodeEditControl::OnEditSelectAll)
    EVT_MENU (myID_SELECTLINE,         CodeEditControl::OnEditSelectLine)
    EVT_MENU (wxID_REDO,               CodeEditControl::OnEditRedo)
    EVT_MENU (wxID_UNDO,               CodeEditControl::OnEditUndo)

    EVT_MENU (myID_BRACEMATCH,         CodeEditControl::OnBraceMatch)
    EVT_MENU (myID_GOTO,               CodeEditControl::OnGoto)
    // view
    EVT_MENU_RANGE (myID_HILIGHTFIRST, myID_HILIGHTLAST,
                                       CodeEditControl::OnHilightLang)
    EVT_MENU (myID_DISPLAYEOL,         CodeEditControl::OnDisplayEOL)
    EVT_MENU (myID_LONGLINEON,         CodeEditControl::OnLongLineOn)
    EVT_MENU (myID_FOLDTOGGLE,         CodeEditControl::OnFoldToggle)
    EVT_MENU (myID_OVERTYPE,           CodeEditControl::OnSetOverType)
    EVT_MENU (myID_READONLY,           CodeEditControl::OnSetReadOnly)
    EVT_MENU (myID_WRAPMODEON,         CodeEditControl::OnWrapmodeOn)
    EVT_MENU (myID_CHARSETANSI,        CodeEditControl::OnUseCharset)
    EVT_MENU (myID_CHARSETMAC,         CodeEditControl::OnUseCharset)
    // extra
    EVT_MENU (myID_CHANGELOWER,        CodeEditControl::OnChangeCase)
    EVT_MENU (myID_CHANGEUPPER,        CodeEditControl::OnChangeCase)
    EVT_MENU (myID_CONVERTCR,          CodeEditControl::OnConvertEOL)
    EVT_MENU (myID_CONVERTCRLF,        CodeEditControl::OnConvertEOL)
    EVT_MENU (myID_CONVERTLF,          CodeEditControl::OnConvertEOL)
    // stc
    EVT_STC_MARGINCLICK (wxID_ANY,     CodeEditControl::OnMarginClick)
    EVT_STC_CHARADDED (wxID_ANY,       CodeEditControl::OnCharAdded)
END_EVENT_TABLE()
