Connect(wxEVT_RIGHT_DOWN, (wxObjectEventFunction)&AstadeStatusBar::OnRightMouseClick);
Connect(ID_COPYSTATUS, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&AstadeStatusBar::CopyStatus);
