std::set<wxString> aSet = theStatechart.GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
	fprintf(specificationFile,"\t\t%s\n\n",(*iter).c_str());