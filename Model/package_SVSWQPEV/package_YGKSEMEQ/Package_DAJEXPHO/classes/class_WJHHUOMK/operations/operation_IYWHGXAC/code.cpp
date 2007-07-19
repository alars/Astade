fprintf(specificationFile, "\t\t//! \\brief This is the default state, before the state machine is initialized.\n");
fprintf(specificationFile, "\t\t//! It does nothing but the initial transition.\n");
fprintf(specificationFile, "\t\tvoid ResetState(CMessage& message);\n\n");

fprintf(implementationFile, "void %s::ResetState(CMessage& message)\n{\n", (const char*)theStatechart.GetName().c_str());

std::set<wxString> aSet;

aSet = theStatechart.GetInitialActions();
fprintf(implementationFile, "\tif (message.Primitive() == dIID_VFSM_MSG_Init)\n\t{\n");

fprintf(implementationFile, "\t\t// Calling the initial actions\n");

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); iter++)
	fprintf(implementationFile, "\t\t%s(message);\n", (const char*)(*iter).c_str());

fprintf(implementationFile, "\t\t// Set the initial State function\n");
fprintf(implementationFile, "\t\tnextState = &%s::Enter_%s;\n", (const char*)theStatechart.GetName().c_str(), (const char*)theStatechart.GetInitialState().c_str());

fprintf(implementationFile, "\t\t// Call the state enter function\n");
fprintf(implementationFile, "\t\tEnterState(message);\n");

fprintf(implementationFile, "\t}\n\telse\n\t\tmessage.NotHandeled();\n");

fprintf(implementationFile, "}\n\n");
