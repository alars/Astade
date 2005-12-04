fprintf(specificationFile,"\t\t//! \\brief This is the enter function for state %s.\n",theState.GetName().c_str());
fprintf(specificationFile,"\t\tvoid Enter_%s(const %s& theEvent);\n\n",theState.GetName().c_str(),theStatechart.GetEventType().c_str());

fprintf(implementationFile,"void %s::Enter_%s(const %s& theEvent)\n{\n",theStatechart.GetName().c_str(),theState.GetName().c_str(),theStatechart.GetEventType().c_str());

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	fprintf(implementationFile,"\t//Call Entry Action.\n");
	fprintf(implementationFile,"\t%s(theEvent);\n",EntryAction.c_str());
}

fprintf(implementationFile,"\t//Set the new state.\n");
fprintf(implementationFile,"\ttheState = &%s::%s;\n",theStatechart.GetName().c_str(),theState.GetName().c_str());

fprintf(implementationFile,"\tnextState = 0; // We stay in this state\n");

fprintf(implementationFile,"}\n\n");