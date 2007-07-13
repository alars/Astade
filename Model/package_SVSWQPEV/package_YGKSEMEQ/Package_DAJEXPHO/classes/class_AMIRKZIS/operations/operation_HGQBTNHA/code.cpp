fprintf(specificationFile, "\t\t//! \\brief This function implements the Timeout. When the Timeout expires this function calls TakeEvent with a Timer event.\n");
fprintf(specificationFile, "\t\tvirtual void Notify();\n\n");

fprintf(implementationFile, "void %s::Notify()\n{\n", (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "#if wxCHECK_VERSION(2,9,0)\n");
fprintf(implementationFile, "\twxTimerEvent aEvent(*this);\n");
fprintf(implementationFile, "#else\n");
fprintf(implementationFile, "\twxTimerEvent aEvent(TIMER_ID);\n");
fprintf(implementationFile, "#endif\n");
fprintf(implementationFile, "\tTakeEvent(aEvent);\n");

fprintf(implementationFile, "}\n\n");
