wxString label = myConfig->Read("Astade/Name");

wxString action = myConfig->Read("Astade/Action1");

if (!action.empty() && !myConfig->Read("Astade/Action2").empty())
	action += "; ";

action += myConfig->Read("Astade/Action2");

if (!action.empty() && !myConfig->Read("Astade/Action3").empty())
	action += "; ";

action += myConfig->Read("Astade/Action3");

if (!action.empty() && !myConfig->Read("Astade/Action4").empty())
	action += "; ";

action += myConfig->Read("Astade/Action4");

label += ": ";
label += action;
label += " ---> ";
label += myConfig->Read("Astade/InitialState");

return label;