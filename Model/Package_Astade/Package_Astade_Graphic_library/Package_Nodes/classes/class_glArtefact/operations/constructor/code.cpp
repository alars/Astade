//~~ glArtefact(glGraphicPanel* parent, long x, long y) [glArtefact] ~~
wxTheColourDatabase->AddColour(wxS("CornflowerBlue"), wxColor(0x64, 0x95, 0xED));

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("used for ..."), wxCommandEventHandler(glArtefact::OnUsed));
AddMenuFunction(wxS("created by ..."), wxCommandEventHandler(glArtefact::OnCreated));
my_YRadius = 23;
static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(2 * my_YRadius);
