fprintf(specificationFile, "//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile, "//! All events for this state machine must inherit from the event base class: \"%s\"\n", (const char*)theStatechart.GetEventType().c_str());
fprintf(specificationFile, "//! Calling this function is allowed only after calling the \"Initialize\" function.\n");
fprintf(specificationFile, "//! \\param me A pointer to the statechart instance.\n");
fprintf(specificationFile, "//! \\param theEvent	The event to be processed.\n");
fprintf(specificationFile, "//! \\param itsID	The ID of the event (used for the internal switch case).\n");
fprintf(specificationFile, "//! \\return Boolean, whether the event was \"taken\" (there was a reaction on that event).\n");

fprintf(specificationFile, "bool %s_TakeEvent(%s* me, const %s& theEvent, eventIDs itsID);\n\n",
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "bool %s_TakeEvent(%s* me, const %s& theEvent, eventIDs itsID)\n{\n",
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());
fprintf(implementationFile, "\tbool ret = (me->*theState)(theEvent,itsID);\n");

fprintf(implementationFile, "\t// Call the state enter function\n");
fprintf(implementationFile, "\tEnterState(theEvent);\n");

fprintf(implementationFile, "\treturn ret;\n");
fprintf(implementationFile, "}\n\n");
