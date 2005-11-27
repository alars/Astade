fprintf(specificationFile,"\t\t//! \\brief This is the default state, before the state machine is initialized.\n");
fprintf(specificationFile,"\t\t//! It does nothing. This makes shure, that there is no crash, when \"TakeEvent\" is called accidently before \"Initialize\".\n");
fprintf(specificationFile,"\t\tvoid NoState(const %s& theEvent);\n\n",theStatechart.GetEventType().c_str());

fprintf(implementationFile,"void %s::NoState(const %s& theEvent){}\n\n",theStatechart.GetName().c_str(),theStatechart.GetEventType().c_str());