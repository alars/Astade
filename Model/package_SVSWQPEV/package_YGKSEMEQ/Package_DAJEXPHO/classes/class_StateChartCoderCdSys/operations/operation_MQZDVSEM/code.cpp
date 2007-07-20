fprintf(specificationFile, "\t\t//! \\brief This is the default state, before the state machine is initialized.\n");
fprintf(specificationFile, "\t\t//! It does nothing. This makes shure, that there is no crash, when \"TakeEvent\" is called accidently before \"Initialize\".\n");
fprintf(specificationFile, "\t\tbool NoState(wxEvent& theEvent);\n\n");

fprintf(implementationFile, "bool %s::NoState(wxEvent& theEvent)\n{\n\treturn false;\n}\n\n", (const char*)theStatechart.GetName().c_str());
