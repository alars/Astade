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

std::list<wxString> aList = GetActions();

for (std::list<wxString>::iterator iter=aList.begin();iter!=aList.end();iter++)
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