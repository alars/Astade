fprintf(specificationFile,"\t\ttypedef void ( %s::* t_state )( const %s& );\n",theStatechart.GetName().c_str(),theStatechart.GetEventType().c_str());
fprintf(specificationFile,"\t\t//! \\brief The pointer, holding the actuel state.\n");
fprintf(specificationFile,"\t\tt_state theState;\n\n");