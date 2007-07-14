fprintf(specificationFile, "\t\t//************* guards **************************\n");

std::set<wxString> aSet = theStatechart.GetGuards();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(specificationFile,"\t\tvirtual bool %s(const %s& theEvent) = 0;\n\n", (const char*)(*iter).c_str(), (const char*)theStatechart.GetEventType().c_str());
