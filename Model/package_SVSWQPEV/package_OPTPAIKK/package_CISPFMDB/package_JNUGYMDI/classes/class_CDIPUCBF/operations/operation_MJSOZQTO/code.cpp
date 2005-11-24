wxFileConfig ownConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

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

return action;