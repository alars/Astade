fprintf(specificationFile,"\t\t//************* actions **************************\n");

std::set<wxString> aSet = theStatechart.GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
	fprintf(specificationFile,"\t\tvirtual void %s(CMessage& message) = 0;\n",(*iter).c_str());