fprintf(specificationFile, "\t//! \\brief The pointer to the handler class.\n");
fprintf(specificationFile, "\t%s_impl* myHandler;\n\n",
                            (const char*)theStatechart.GetName().c_str());
