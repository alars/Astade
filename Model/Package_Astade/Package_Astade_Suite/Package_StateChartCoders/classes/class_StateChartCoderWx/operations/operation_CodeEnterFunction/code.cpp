fprintf(specificationFile, "\t\t//! \\brief This function calls the current enter Function until a stable state is reached.\n");
fprintf(specificationFile, "\t\t//! \\param theEvent	The event, passed to the actions and guards.\n");
fprintf(specificationFile, "\t\tvoid EnterState(wxEvent& theEvent);\n\n");

fprintf(implementationFile, "void %s::EnterState(wxEvent& theEvent)\n{\n", (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "\twhile(nextState)\n\t\t(this->*nextState)(theEvent);\n");

fprintf(implementationFile, "}\n\n");
