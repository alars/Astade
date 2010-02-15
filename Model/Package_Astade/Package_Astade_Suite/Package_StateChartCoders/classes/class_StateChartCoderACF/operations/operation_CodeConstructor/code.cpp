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

fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\tNOTIFY_CONSTRUCTOR(5, \"%s\", \" \")\n", 
                            (const char*)theStatechart.GetName().c_str()); 
fprintf(implementationFile, "\t#endif\n");

fprintf(implementationFile, "\t// Call the message framework constructor\n");
fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\tACF_MessageReceiver_Constructor(&me->MessageReceiver_base, \"%s\", (void(*)(void*, ACF_Message*))&%s_TakeEvent);\n",
                           (const char*)theStatechart.GetName().c_str(),
                           (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "\t#else\n");
fprintf(implementationFile, "\tACF_MessageReceiver_Constructor(&me->MessageReceiver_base, 0, (void(*)(void*, ACF_Message*))&%s_TakeEvent);\n",
                           (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "\t#endif\n");

fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\tvoidRETURN;\n");
fprintf(implementationFile, "\t#endif\n");

fprintf(implementationFile, "}\n\n");

fprintf(implementationFile, "//! \\brief Destructor.\n");
fprintf(implementationFile, "void %s_Destructor(%s* me)\n",
                           (const char*)theStatechart.GetName().c_str(),
                           (const char*)theStatechart.GetName().c_str());
fprintf(implementationFile, "{\n");
fprintf(implementationFile, "\t#ifdef _TRACE_\n");

fprintf(implementationFile, "\tNOTIFY_DESTRUCTOR(5, \"%s\")\n", 
                            (const char*)theStatechart.GetName().c_str()); 
fprintf(implementationFile, "\t#endif\n");

fprintf(implementationFile, "\tACF_MessageReceiver_Destructor(&me->MessageReceiver_base);\n");

fprintf(implementationFile, "\t#ifdef _TRACE_\n");
fprintf(implementationFile, "\tvoidRETURN;\n");
fprintf(implementationFile, "\t#endif\n");

fprintf(implementationFile, "}\n\n");
