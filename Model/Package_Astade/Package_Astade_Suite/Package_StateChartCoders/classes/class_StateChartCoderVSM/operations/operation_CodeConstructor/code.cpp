fprintf(specificationFile, "\t\t//! \\brief Constructor.\n");
fprintf(specificationFile, "\t\t%s(long liMachineID, const char acMachineName[]);\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(implementationFile, "%s::%s(long liMachineID, const char acMachineName[]) :\n\tCVirtualStateMachine(liMachineID,acMachineName),\n\tm_RunningTimer(0)\n{\n}\n\n", (const char*)theStatechart.GetName().c_str(), (const char*)theStatechart.GetName().c_str());
