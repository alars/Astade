fprintf(specificationFile, "//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile, "//! Calling this function is allowed only after calling the \"Initialize\" function.\n");
fprintf(specificationFile, "//! \\param me A pointer to the statechart instance.\n");
fprintf(specificationFile, "//! \\param theEvent The event to be processed.\n");

fprintf(specificationFile, "void %s_TakeEvent(%s* me, %s* theEvent);\n\n",
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetEventType().c_str());

fprintf(implementationFile, "void %s_TakeEvent(%s* me, %s* theEvent)\n{\n",
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());
                            
fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.me_text);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\":\");\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.Name);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\" ==> \");\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.me_text);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\":\");\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.Name);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\" TakeEvent\\n\");\n");
fprintf(implementationFile, "\t#endif\n");
                            
fprintf(implementationFile, "\t(me->theState)(me, theEvent);\n");

fprintf(implementationFile, "\t// Call the state enter function\n");
fprintf(implementationFile, "\t%s_EnterState(me, theEvent);\n",
                            (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.me_text);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\":\");\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.Name);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\" <== \");\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.me_text);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\":\");\n");
fprintf(implementationFile, "\t\tACF_trace(me->MessageReceiver_base.Name);\n");
fprintf(implementationFile, "\t\tACF_trace((char*)\"\\n\");\n");
fprintf(implementationFile, "\t#endif\n");

fprintf(implementationFile, "}\n\n");
