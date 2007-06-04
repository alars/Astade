fprintf(specificationFile,"\t\t//************* timeouts **************************\n");

std::set<wxString> aSet = theStatechart.GetTimeouts();

for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
	fprintf(specificationFile,"\t\tunsigned int %s;\n",(*iter).c_str());