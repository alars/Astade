wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString label = theConfig.Read("Astade/Trigger");

wxString guard = theConfig.Read("Astade/Guard");

if (!guard.empty())
{
	label += " [";
	label += guard;
	label += "]";
}

label += " / ";

wxString action = theConfig.Read("Astade/Action1");

if (!action.empty() && !theConfig.Read("Astade/Action2").empty())
	action += "; ";

action += theConfig.Read("Astade/Action2");

if (!action.empty() && !theConfig.Read("Astade/Action3").empty())
	action += "; ";

action += theConfig.Read("Astade/Action3");

if (!action.empty() && !theConfig.Read("Astade/Action4").empty())
	action += "; ";

action += theConfig.Read("Astade/Action4");

label += action;

wxString TransitionType = theConfig.Read("Astade/TransitionType");

if (TransitionType=="Normal")
{
	label += " ---> ";
	label += theConfig.Read("Astade/DestinationState");
}

return label;