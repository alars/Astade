//~~ AstadeStatusBar(wxWindow* parent, wxWindowID id, long style, const wxString& name) [AstadeStatusBar] ~~

Connect(wxEVT_RIGHT_DOWN, (wxObjectEventFunction)&AstadeStatusBar::OnRightMouseClick);
Connect(ID_COPYSTATUS, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&AstadeStatusBar::CopyStatus);
Connect(ID_COPYSTATUS_RELATIVE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&AstadeStatusBar::CopyStatus);
