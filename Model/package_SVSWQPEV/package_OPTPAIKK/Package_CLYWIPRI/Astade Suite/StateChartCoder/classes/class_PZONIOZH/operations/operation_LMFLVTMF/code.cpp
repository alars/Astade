fprintf(implementationFile,"BEGIN_EVENT_TABLE(ImpOf_%s,wxEvtHandler)\n",theStatechart.GetName().c_str());

std::set<wxString> aSet = theStatechart.GetTrigger();

int evtCount=1;
for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
{
	wxString event = *iter;
	if (event.Left(4)=="EVT_" && event.Right(1)==")")
	{
		event.Truncate(event.size()-1);
		wxString function;
		function.Printf(",ImpOf_%s::HandleEventNo%03d)",theStatechart.GetName().c_str(),evtCount++);
		event += function;
		fprintf(implementationFile,"\t%s\n",event.c_str());
	}
}

fprintf(implementationFile,"END_EVENT_TABLE()\n\n");