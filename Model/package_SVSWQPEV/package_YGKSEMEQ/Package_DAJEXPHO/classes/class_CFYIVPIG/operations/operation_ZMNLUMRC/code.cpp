fprintf(specificationFile,"\t//! \\brief The pointer to the enter function of the next state.\n");
fprintf(specificationFile,"\tvoid (*nextState)(struct %s* me, %s*);\n\n",
                                (const char*)theStatechart.GetName().c_str(), 
                                (const char*)theStatechart.GetEventType().c_str());
