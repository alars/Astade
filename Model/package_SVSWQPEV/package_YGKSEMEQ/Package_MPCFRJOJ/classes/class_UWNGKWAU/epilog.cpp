BEGIN_EVENT_TABLE(CodeEditFrame,GeneratedFrame)

    EVT_BUTTON(CANCEL_BUTTON, CodeEditFrame::OnCancel)
    EVT_BUTTON(OK_BUTTON, CodeEditFrame::OnOk)
    EVT_BUTTON(SEARCH, CodeEditFrame::OnSearch)
    EVT_CHECKBOX(LINE_NUMBER_BOX, CodeEditFrame::OnLineNumberChange) 
    EVT_CHECKBOX(WHITESPACE_BOX, CodeEditFrame::OnWhitespaceChange) 
    EVT_CHECKBOX(INDENT_BOX, CodeEditFrame::OnShowIndentChange) 
    EVT_FIND_CLOSE(wxID_ANY, CodeEditFrame::OnFindEnd) 

END_EVENT_TABLE()
