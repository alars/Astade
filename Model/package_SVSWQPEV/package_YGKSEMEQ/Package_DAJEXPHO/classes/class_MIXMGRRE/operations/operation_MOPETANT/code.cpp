fprintf(specificationFile, "\t//! \\brief The pointer, holding the handler class.\n");
fprintf(specificationFile, "\t%s_impl* myHandler;\n\n",
                            (const char*)theStatechart.GetName().c_str(),
                            (const char*)theStatechart.GetEventType().c_str());
