fprintf(specificationFile, "//! \\brief Constructor.\n");
fprintf(specificationFile, "extern void %s_Constructor(%s* me);\n\n",
                           (const char*)theStatechart.GetName().c_str(),
                           (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "//! \\brief Destructor.\n");
fprintf(specificationFile, "extern void %s_Destructor(%s* me);\n\n",
                           (const char*)theStatechart.GetName().c_str(),
                           (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "//! \\brief Constructor.\n");
fprintf(implementationFile, "void %s_Constructor(%s* me)\n",
                           (const char*)theStatechart.GetName().c_str(),
                           (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "{\n");
fprintf(implementationFile, "}\n\n");

fprintf(implementationFile, "//! \\brief Destructor.\n");
fprintf(implementationFile, "void %s_Destructor(%s* me)\n",
                           (const char*)theStatechart.GetName().c_str(),
                           (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "{\n");
fprintf(implementationFile, "}\n\n");
