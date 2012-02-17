//~~ glNote(glGraphicPanel* parent, long x, long y) [glNote] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("attach to ..."), wxCommandEventHandler(glArtefact::OnAttach));
my_YRadius = 23;
static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(2 * my_YRadius);
