fprintf(specificationFile, "\t\t//! \\brief This is the default state, before the state machine is initialized.\n");
fprintf(specificationFile, "\t\t//! It does nothing. This makes shure, that there is no crash, when \"TakeEvent\" is called accidently before \"Initialize\".\n");
fprintf(specificationFile, "\t\tbool NoState(const %s& theEvent, eventIDs itsID);\n\n", (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "bool %s::NoState(const %s& theEvent, eventIDs itsID)\n{\n\treturn false;\n}\n\n", (const char*)theStatechart.GetName().c_str(), (const char*)theStatechart.GetEventType().c_str());
