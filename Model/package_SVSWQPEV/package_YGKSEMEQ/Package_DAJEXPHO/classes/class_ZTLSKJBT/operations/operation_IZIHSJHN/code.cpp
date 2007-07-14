fprintf(specificationFile,"\t\t//************* actions **************************\n");

std::set<wxString> aSet = theStatechart.GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(specificationFile, "\t\tvirtual void %s(const %s& theEvent) = 0;\n\n", (const char*)(*iter).c_str(), (const char*)theStatechart.GetEventType().c_str());
