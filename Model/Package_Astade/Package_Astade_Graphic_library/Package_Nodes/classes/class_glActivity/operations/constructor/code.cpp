//~~ glActivity(glGraphicPanel* parent, long x, long y) [glActivity] ~~

wxTheColourDatabase->AddColour(wxS("Lemon Chiffon"), wxColor(0xFF, 0xF8, 0xC6));

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("create ..."), wxCommandEventHandler(glActivity::OnCreate));
AddMenuFunction(wxS("use ..."), wxCommandEventHandler(glActivity::OnDepend));