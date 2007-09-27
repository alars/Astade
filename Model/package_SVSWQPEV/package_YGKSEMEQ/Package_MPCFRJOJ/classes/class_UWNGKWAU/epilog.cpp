BEGIN_EVENT_TABLE(CodeEditFrame,GeneratedFrame)

	EVT_BUTTON(CANCEL_BUTTON, CodeEditFrame::OnCancel)
	EVT_BUTTON(OK_BUTTON, CodeEditFrame::OnOk)
    EVT_CHECKBOX(LINE_NUMBER_BOX, CodeEditFrame::OnLineNumberChange) 
END_EVENT_TABLE()
