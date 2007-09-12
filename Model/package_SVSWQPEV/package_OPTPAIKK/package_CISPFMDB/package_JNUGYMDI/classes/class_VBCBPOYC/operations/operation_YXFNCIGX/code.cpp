wxString label = GetName();

if (!myConfig->Read("Astade/EntryAction").empty())
	label += " Entry: " + myConfig->Read("Astade/EntryAction");

if (!myConfig->Read("Astade/ExitAction").empty())
	label += " Exit: " + myConfig->Read("Astade/ExitAction");

return label;