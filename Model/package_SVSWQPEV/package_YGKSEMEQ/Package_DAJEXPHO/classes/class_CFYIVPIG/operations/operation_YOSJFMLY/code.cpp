fprintf(specificationFile, "enum %s_eventIDs\n{\n",(const char*)theStatechart.GetName().c_str());

std::set<wxString> aSet = theStatechart.GetTrigger();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(specificationFile, "\tID_%s,\n", (const char*)(*iter).c_str());

fprintf(specificationFile, "};\n\n");
