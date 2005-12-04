fprintf(specificationFile,"\t\t//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile,"\t\t//! All events for this state machine must inherit from the event base class: \"%s\"\n",theStatechart.GetEventType().c_str());
fprintf(specificationFile,"\t\t//! Calling this function is allowed only after calling the \"Initialize\" function.\n");
fprintf(specificationFile,"\t\t//! \\param theEvent	The event to be processed.\n");
fprintf(specificationFile,"\t\t//! \\param itsID	The ID of the event (used for the internal switch case).\n");
fprintf(specificationFile,"\t\t//! \\return Boolean, wether the event was \"taken\" (there was a reaction on that event).\n");

fprintf(specificationFile,"\t\tbool TakeEvent(const %s& theEvent, eventIDs itsID);\n\n",theStatechart.GetEventType().c_str());

fprintf(implementationFile,"bool %s::TakeEvent(const %s& theEvent, eventIDs itsID)\n{\n",theStatechart.GetName().c_str(),theStatechart.GetEventType().c_str());
fprintf(implementationFile,"\tbool ret = (this->*theState)(theEvent,itsID);\n");

fprintf(implementationFile,"\t// Call the state enter function\n");
fprintf(implementationFile,"\tEnterState(theEvent);\n");

fprintf(implementationFile,"\treturn ret;\n");
fprintf(implementationFile,"}\n\n");