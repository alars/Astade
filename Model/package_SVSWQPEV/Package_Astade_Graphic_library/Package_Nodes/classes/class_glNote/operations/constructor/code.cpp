Refresh();
AddMenuSeparator();
AddMenuFunction("attach to ...",wxCommandEventHandler(glNote::OnAttach));
my_YRadius = 23;
static_cast<glNoteGravityArea*>(myGravityArea)->SetHight(2*my_YRadius);
