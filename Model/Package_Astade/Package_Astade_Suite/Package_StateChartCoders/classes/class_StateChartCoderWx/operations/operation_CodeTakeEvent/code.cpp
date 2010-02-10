fprintf(specificationFile, "\t\t//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile, "\t\t//! All events for this state machine must inherit from the event base class: \"%s\"\n", (const char*)theStatechart.GetEventType().c_str());
fprintf(specificationFile, "\t\t//! Calling this function is allowed only after calling the \"Initialize\" function.\n");
fprintf(specificationFile, "\t\t//! \\param theEvent	The event to be processed.\n");
fprintf(specificationFile, "\t\t//! \\return Boolean, whether the event was \"taken\" (there was a reaction on that event).\n");

fprintf(specificationFile, "\t\tbool TakeEvent(wxEvent& theEvent);\n\n");

fprintf(implementationFile, "bool %s::TakeEvent(wxEvent& theEvent)\n{\n", (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "\tbool ret = (this->*theState)(theEvent);\n");

fprintf(implementationFile, "\t// Call the state enter function\n");
fprintf(implementationFile, "\tEnterState(theEvent);\n");

fprintf(implementationFile, "\treturn ret;\n");
fprintf(implementationFile, "}\n\n");
