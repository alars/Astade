fprintf(specificationFile,"\t//! \\brief The function pointer to the enter function of the next state.\n");
fprintf(specificationFile,"\tvoid (*nextState)(%s* me, const %s& );\n\n",
                                (const char*)theStatechart.GetName().c_str(), 
                                (const char*)theStatechart.GetEventType().c_str());
