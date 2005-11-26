fprintf(specificationFile,"\t\t//! \\brief Call this function once, to initialize the state machine.\n");
fprintf(specificationFile,"\t\t//! This will call all initial actions and enter state \"%s\".\n",theStatechart.GetInitialState().c_str());
fprintf(specificationFile,"\t\t//! The actions are called with the event, passed to this function.\n");
fprintf(specificationFile,"\t\t//! \\param theEvent	The event, passed to the initial actions.\n");
fprintf(specificationFile,"\t\tvoid Initialize(%s theEvent);\n\n",theStatechart.GetEventType().c_str());