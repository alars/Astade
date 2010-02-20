fprintf(specificationFile,"//! \\brief Call this function once, to initialize the state machine.\n");
fprintf(specificationFile, "//! This will call all initial actions and enter state \"%s\".\n", (const char*)theStatechart.GetInitialState().c_str());
fprintf(specificationFile, "//! The actions are called with the event, passed to this function.\n");
fprintf(specificationFile, "//! \\param me A pointer to the statechart instance.\n");
fprintf(specificationFile, "//! \\param handler A pointer to the instance of the handler struct.\n");
fprintf(specificationFile, "//! \\param theEvent The event, passed to the initial actions.\n");
fprintf(specificationFile, "void %s_Initialize(%s* me, %s_impl* handler, const %s& theEvent);\n\n", 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "void %s_Initialize(%s* me, %s_impl* handler, const %s& theEvent)\n{\n",
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());

std::list<wxString> aList = theStatechart.GetInitialActions();
fprintf(implementationFile, "\t// Set my handler\n");
fprintf(implementationFile, "\tme->myHandler = handler;\n\n");

fprintf(implementationFile, "\t// Calling the initial actions\n");

for (std::list<wxString>::iterator iter=aList.begin();iter!=aList.end();iter++)
	fprintf(implementationFile, "\t%s_impl_%s(me->myHandler, theEvent);\n",
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)(*iter).c_str());

fprintf(implementationFile, "\t// Set the initial State function\n");
fprintf(implementationFile, "\tme->nextState = &%s_Enter_%s;\n",
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetInitialState().c_str());

fprintf(implementationFile, "\t// Call the state enter function\n");
fprintf(implementationFile, "\t%s_EnterState(me, theEvent);\n",
                            (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "}\n\n");
