fprintf(specificationFile, "\t//! \\brief The pointer, holding the current state.\n");
fprintf(specificationFile, "\tbool (*theState)(const %s&, eventIDs);\n\n", (const char*)theStatechart.GetEventType().c_str());
