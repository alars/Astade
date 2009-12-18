fprintf(specificationFile, "//! \\brief This function calls the current enter Function until a stable state is reached.\n");
fprintf(specificationFile, "//! \\param theEvent	The event, passed to the actions and guards.\n");
fprintf(specificationFile, "void %s_EnterState(%s* me, %s* theEvent);\n\n",
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "void %s_EnterState(%s* me, %s* theEvent)\n{\n", 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "\twhile(me->nextState)\n\t\t(me->nextState)(me, theEvent);\n");

fprintf(implementationFile, "}\n\n");
