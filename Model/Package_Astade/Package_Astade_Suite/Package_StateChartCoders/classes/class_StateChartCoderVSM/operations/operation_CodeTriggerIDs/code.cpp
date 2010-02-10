fprintf(specificationFile, "\t\t// The following event IDs are used:\n");

std::set<wxString> aSet = theStatechart.GetTrigger();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(specificationFile, "\t\t// %s\n", (const char*)(*iter).c_str());

fprintf(specificationFile, "\n");
