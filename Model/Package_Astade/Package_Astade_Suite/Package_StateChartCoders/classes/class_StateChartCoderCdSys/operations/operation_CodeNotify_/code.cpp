//~~ void CodeNotify_(AdeStatechart& theStatechart) [StateChartCoderCdSys] ~~

fprintf(specificationFile, "\t\t//! \\brief This function Implements the Timeout. When the Timeout expires this function calls TakeEvent with a Timer eventheEvent	The event.\n");
fprintf(specificationFile, "\t\tvirtual void Notify();\n\n");

fprintf(implementationFile, "void %s::Notify()\n{\n", (const char*)theStatechart.GetName().utf8_str());

fprintf(implementationFile, "\twxTimerEvent anEvent(TIMER_ID);\n");
fprintf(implementationFile, "\tTakeEvent(anEvent);\n");

fprintf(implementationFile, "}\n\n");
