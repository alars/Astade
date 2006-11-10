fprintf(specificationFile,"\t\t//************* actions **************************\n");

std::set<wxString> aSet = theStatechart.GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
	fprintf(specificationFile,"\t\tvirtual void %s(wxEvent& theEvent) = 0;\n\n",(*iter).c_str());