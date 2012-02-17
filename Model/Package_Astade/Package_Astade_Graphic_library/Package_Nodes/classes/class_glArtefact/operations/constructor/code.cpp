//~~ glArtefact(glGraphicPanel* parent, long x, long y) [glArtefact] ~~
wxTheColourDatabase->AddColour(wxS("CornflowerBlue"), wxColor(0x64, 0x95, 0xED));

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("attach to ..."), wxCommandEventHandler(glArtefact::OnAttach));
my_YRadius = 23;
static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(2 * my_YRadius);
