wxString label = myConfig->Read("Astade/Trigger");
wxString guard = myConfig->Read("Astade/Guard");

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

wxString TransitionType = myConfig->Read("Astade/TransitionType");

if (TransitionType=="Normal")
{
	label += " ---> ";
	label += myConfig->Read("Astade/DestinationState");
}

return label;