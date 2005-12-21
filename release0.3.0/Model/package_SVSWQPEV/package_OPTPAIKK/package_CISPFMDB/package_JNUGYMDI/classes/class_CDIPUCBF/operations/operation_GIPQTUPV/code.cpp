wxFileConfig ownConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString label = ownConfig.Read("Astade/Name");

wxString action = ownConfig.Read("Astade/Action1");

if (!action.empty() && !ownConfig.Read("Astade/Action2").empty())
	action += "; ";

action += ownConfig.Read("Astade/Action2");

if (!action.empty() && !ownConfig.Read("Astade/Action3").empty())
	action += "; ";

action += ownConfig.Read("Astade/Action3");

if (!action.empty() && !ownConfig.Read("Astade/Action4").empty())
	action += "; ";

action += ownConfig.Read("Astade/Action4");

label += ": ";
label += action;
label += " ---> ";
label += ownConfig.Read("Astade/InitialState");

return label;