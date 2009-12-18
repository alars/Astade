fprintf(specificationFile, "\t//! \\brief The state chart is a ACF_MessageReceiver so we need this member here first.\n");
fprintf(specificationFile, "\tACF_MessageReceiver MessageReceiver_base;\n\n");

fprintf(specificationFile, "\t//! \\brief The pointer, holding the current state.\n");
fprintf(specificationFile, "\tvoid (*theState)(%s* me, %s*);\n\n", 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());
