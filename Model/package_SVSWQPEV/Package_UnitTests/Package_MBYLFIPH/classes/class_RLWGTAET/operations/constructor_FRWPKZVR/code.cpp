Refresh();
AddMenuSeparator();
AddMenuFunction("set male",wxCommandEventHandler(scPerson::SetMale));
AddMenuFunction("set female",wxCommandEventHandler(scPerson::SetFemale));
AddMenuFunction("set child",wxCommandEventHandler(scPerson::SetChild));
AddMenuFunction("set adult",wxCommandEventHandler(scPerson::SetAdult));

