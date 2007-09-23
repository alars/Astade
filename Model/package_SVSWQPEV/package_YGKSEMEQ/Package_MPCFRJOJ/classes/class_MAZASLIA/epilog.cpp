BEGIN_EVENT_TABLE(CodeEditControl,wxTextCtrl)
	EVT_TEXT(wxID_ANY, CodeEditControl::OnTextChange)
END_EVENT_TABLE()