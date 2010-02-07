std::set<wxString> aSet = theStatechart.GetGuards();

if (aSet.empty())
    return;

fprintf(implementationFile, "//************* guards **************************\n");

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(implementationFile, "extern int %s_impl_%s(void*, ACF_Message* event);\n",
	                            (const char*)theStatechart.GetName().c_str(),
	                            (const char*)(*iter).c_str());
	                            
fprintf(implementationFile,"\n");
