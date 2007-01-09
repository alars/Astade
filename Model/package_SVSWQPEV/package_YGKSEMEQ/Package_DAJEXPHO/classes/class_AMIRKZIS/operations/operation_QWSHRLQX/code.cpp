fprintf(specificationFile,"\t\t//! \\brief This function calls the actuell enter Function until a stabil state is reached.\n");
fprintf(specificationFile,"\t\t//! \\param theEvent	The event, passed to the actions and guards.\n");
fprintf(specificationFile,"\t\tvoid EnterState(wxEvent& theEvent);\n\n");

fprintf(implementationFile,"void %s::EnterState(wxEvent& theEvent)\n{\n",theStatechart.GetName().c_str());

fprintf(implementationFile,"\twhile(nextState)\n\t\t(this->*nextState)(theEvent);\n");

fprintf(implementationFile,"}\n\n");
