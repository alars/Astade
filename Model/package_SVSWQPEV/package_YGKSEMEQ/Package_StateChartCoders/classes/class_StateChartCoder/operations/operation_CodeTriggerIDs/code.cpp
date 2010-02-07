fprintf(specificationFile, "\t\tenum eventIDs\n\t\t{\n");

std::set<wxString> aSet = theStatechart.GetTrigger();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(specificationFile, "\t\t\tID_%s,\n", (const char*)(*iter).c_str());

fprintf(specificationFile, "\t\t};\n\n");
