fprintf(specificationFile, "\t\t//! \\brief This is the default state before the state machine is initialized.\n");
fprintf(specificationFile, "\t\t//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentially before \"Initialize\".\n");
fprintf(specificationFile, "\t\tbool NoState(wxEvent& theEvent);\n\n");

fprintf(implementationFile, "bool %s::NoState(wxEvent& theEvent)\n{\n\treturn false;\n}\n\n", (const char*)theStatechart.GetName().c_str());
