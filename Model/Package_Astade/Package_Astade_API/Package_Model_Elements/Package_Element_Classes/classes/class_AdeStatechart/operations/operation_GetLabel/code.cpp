wxString label = myConfig->Read(wxS("Astade/Name"));

wxString action = myConfig->Read(wxS("Astade/Action1"));

if (!action.empty() && !myConfig->Read(wxS("Astade/Action2")).empty())
	action += wxS("; ");

action += myConfig->Read(wxS("Astade/Action2"));

if (!action.empty() && !myConfig->Read(wxS("Astade/Action3")).empty())
	action += wxS("; ");

action += myConfig->Read(wxS("Astade/Action3"));

if (!action.empty() && !myConfig->Read(wxS("Astade/Action4")).empty())
	action += wxS("; ");

action += myConfig->Read(wxS("Astade/Action4"));

label += wxS(": ");
label += action;
label += wxS(" ---> ");
label += myConfig->Read(wxS("Astade/InitialState"));

return label;
