std::set<wxString> aSet = theStatechart.GetTrigger();

aSet.insert("ACF_timeout");

fprintf(specificationFile, "//All used events are declared extern, here. They must be defined somewhere else!\n");

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(specificationFile, "extern const char* %s;\n", (const char*)(*iter).c_str());

fprintf(specificationFile, "\n");

