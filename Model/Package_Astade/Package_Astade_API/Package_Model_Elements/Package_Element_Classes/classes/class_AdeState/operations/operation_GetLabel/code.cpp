wxString label = GetName();

if (!myConfig->Read(wxS("Astade/EntryAction")).empty())
	label += wxS(" Entry: ") + myConfig->Read(wxS("Astade/EntryAction"));

if (!myConfig->Read(wxS("Astade/ExitAction")).empty())
	label += wxS(" Exit: ") + myConfig->Read(wxS("Astade/ExitAction"));

return label;
