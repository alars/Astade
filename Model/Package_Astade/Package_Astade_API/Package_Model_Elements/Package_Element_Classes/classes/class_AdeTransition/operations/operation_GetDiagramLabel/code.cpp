//~~ wxString GetDiagramLabel() [AdeTransition] ~~
wxString label = myConfig->Read(wxS("Astade/Trigger"));

wxString guard = myConfig->Read(wxS("Astade/Guard"));

if (!guard.empty())
{
	label += wxS(" [");
	label += guard;
	label += wxS("]");
}

label += wxS(" / ");

wxString action;

std::list<wxString> aList = GetActions();

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
{
	if (!action.empty())
		action += wxS("; ");
	action += *iter;
}

label += action;

wxString TransitionType = myConfig->Read(wxS("Astade/TransitionType"));

return label;
