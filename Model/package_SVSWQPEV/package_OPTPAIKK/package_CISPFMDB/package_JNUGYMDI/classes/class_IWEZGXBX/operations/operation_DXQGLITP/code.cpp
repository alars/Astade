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

wxString action;

std::set<wxString> aSet = GetActions();

for (std::set<wxString>::iterator iter=aSet.begin();iter!=aSet.end();iter++)
{
	if (!action.empty())
		action += "; ";
	action += *iter;
}

label += action;

wxString TransitionType = theConfig.Read("Astade/TransitionType");

if (TransitionType=="Normal")
{
	label += " ---> ";
	label += theConfig.Read("Astade/DestinationState");
}

return label;