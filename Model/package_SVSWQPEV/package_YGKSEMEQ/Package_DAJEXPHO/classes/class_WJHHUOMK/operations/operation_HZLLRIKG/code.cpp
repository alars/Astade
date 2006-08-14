fprintf(specificationFile,"\t\t//************* guards **************************\n");

std::set<wxString> aSet = theStatechart.GetGuards();

for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
	fprintf(specificationFile,"\t\tvirtual bool %s(CMessage& message) = 0;\n\n",(*iter).c_str());