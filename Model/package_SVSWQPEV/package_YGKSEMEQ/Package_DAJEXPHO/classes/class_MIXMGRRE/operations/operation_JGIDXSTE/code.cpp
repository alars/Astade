fprintf(specificationFile,"\t\t//! \\brief The function pointer to the enter function of the next state.\n");
fprintf(specificationFile,"\t\tvoid ( %s::* nextState )( const %s& );\n\n", (const char*)theStatechart.GetName().c_str(), (const char*)theStatechart.GetEventType().c_str());
