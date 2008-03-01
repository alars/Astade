fprintf(specificationFile, "\t//! \\brief The pointer, holding the current state.\n");
fprintf(specificationFile, "\tbool (*theState)(%s* me, const %s&, eventIDs);\n\n", 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());
