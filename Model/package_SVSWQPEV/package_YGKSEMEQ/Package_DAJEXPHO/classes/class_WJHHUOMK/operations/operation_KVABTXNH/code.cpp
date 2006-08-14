fprintf(specificationFile,"\t\t//! \\brief Constructor.\n");
fprintf(specificationFile,"\t\t%s(long liMachineID, const char acMachineName[]);\n\n",theStatechart.GetName().c_str());

fprintf(implementationFile,"%s::%s(long liMachineID, const char acMachineName[]) :\n\tCVirtualStateMachine(liMachineID,acMachineName)\n{\n}\n\n",theStatechart.GetName().c_str(),theStatechart.GetName().c_str(),theStatechart.GetName().c_str());