fprintf(specificationFile,"\t\t//! \\brief The pointer, holding the actuel state.\n");
fprintf(specificationFile,"\t\tbool ( %s::* theState )(wxEvent&);\n\n",theStatechart.GetName().c_str());