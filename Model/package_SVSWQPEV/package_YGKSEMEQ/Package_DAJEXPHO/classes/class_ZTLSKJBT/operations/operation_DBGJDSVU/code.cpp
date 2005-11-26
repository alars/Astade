fprintf(specificationFile,"\t\t//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile,"\t\t//! All events for this state machine must inherit from the event base class: \"%s\"\n",theStatechart.GetEventType().c_str());
fprintf(specificationFile,"\t\t//! \\param theEvent	The event to be processed.\n");
fprintf(specificationFile,"\t\tvoid TakeEvent(%s theEvent);\n\n",theStatechart.GetEventType().c_str());