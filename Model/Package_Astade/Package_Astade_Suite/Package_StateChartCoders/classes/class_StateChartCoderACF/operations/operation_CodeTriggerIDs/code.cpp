std::set<wxString> aSet = theStatechart.GetTrigger();

if (aSet.empty())
    return;

fprintf(implementationFile,"//************* events ***************************\n");

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(implementationFile, "extern const char* %s;\n", (const char*)(*iter).c_str());

fprintf(implementationFile, "\n");
