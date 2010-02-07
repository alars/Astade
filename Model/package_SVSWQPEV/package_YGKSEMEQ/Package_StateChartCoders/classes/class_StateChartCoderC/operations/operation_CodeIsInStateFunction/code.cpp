fprintf(specificationFile, "//! \\brief This checks if the machine is in state \"%s\".\n", (const char*)theState.GetName().c_str());
fprintf(specificationFile, "//! \\param me A pointer to the statechart instance.\n");
fprintf(specificationFile, "//! \\return is in state.\n");
fprintf(specificationFile, "inline bool %s_IsIn%s(%s* me){return (me->theState==&%s_%s);};\n\n", 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theState.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theStatechart.GetName().c_str(), 
                            (const char*)theState.GetName().c_str());
