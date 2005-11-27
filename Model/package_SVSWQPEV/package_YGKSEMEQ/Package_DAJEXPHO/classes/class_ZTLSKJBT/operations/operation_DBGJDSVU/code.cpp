fprintf(specificationFile,"\t\t//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile,"\t\t//! All events for this state machine must inherit from the event base class: \"%s\"\n",theStatechart.GetEventType().c_str());
fprintf(specificationFile,"\t\t//! Calling this function is allowed only after calling the \"Initialize\" function.\n");
fprintf(specificationFile,"\t\t//! \\param theEvent	The event to be processed.\n");
fprintf(specificationFile,"\t\tvoid TakeEvent(const %s& theEvent);\n\n",theStatechart.GetEventType().c_str());

fprintf(implementationFile,"void %s::TakeEvent(const %s& theEvent)\n{\n\t(this->*theState)(theEvent);\n}\n\n",theStatechart.GetName().c_str(),theStatechart.GetEventType().c_str());