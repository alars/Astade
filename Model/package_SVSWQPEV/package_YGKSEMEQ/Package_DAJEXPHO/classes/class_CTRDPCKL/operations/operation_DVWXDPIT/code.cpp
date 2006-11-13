fprintf(specificationFile,"\t\t//! \\brief Call this function once, to initialize the state machine.\n");
fprintf(specificationFile,"\t\t//! Calling this function a second time will have no effect!\n");
fprintf(specificationFile,"\t\t//! This will call all initial actions and enter state \"%s\".\n",theStatechart.GetInitialState().c_str());
fprintf(specificationFile,"\t\t//! The actions are called with the event, passed to this function.\n");
fprintf(specificationFile,"\t\t//! \\param theEvent	The event, passed to the initial actions.\n");
fprintf(specificationFile,"\t\tvoid Initialize(wxEvent& theEvent);\n\n");

fprintf(implementationFile,"void %s::Initialize(wxEvent& theEvent)\n{\n",theStatechart.GetName().c_str());

fprintf(implementationFile,"\tmyImplementation->Initialize(theEvent);\n");

fprintf(implementationFile,"}\n\n");
