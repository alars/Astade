//~~ glActivity(glGraphicPanel* parent, long x, long y) [glActivity] ~~
wxTheColourDatabase->AddColour(wxString("Lemon Chiffon"), wxColor(0xFF, 0xF8, 0xC6));

Refresh();
AddMenuSeparator();
AddMenuFunction("provide interface",wxCommandEventHandler(glActivity::OnProvide));
AddMenuFunction("use",wxCommandEventHandler(glActivity::OnUse));
