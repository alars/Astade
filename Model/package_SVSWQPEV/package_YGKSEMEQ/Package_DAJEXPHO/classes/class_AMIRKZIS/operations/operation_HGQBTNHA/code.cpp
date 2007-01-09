fprintf(specificationFile,"\t\t//! \\brief This function Implements the Timeout. When the Timeout expires this function calls TakeEvent with a Timer eventheEvent	The event.\n");
fprintf(specificationFile,"\t\tvirtual void Notify();\n\n");

fprintf(implementationFile,"void %s::Notify()\n{\n",theStatechart.GetName().c_str());

fprintf(implementationFile,"\twxTimerEvent aEvent(TIMER_ID);\n");
fprintf(implementationFile,"\tTakeEvent(aEvent);\n");

fprintf(implementationFile,"}\n\n");
