fprintf(specificationFile,"\t\t//! \\brief This is the state function for state %s.\n",theState.GetName().c_str());
fprintf(specificationFile,"\t\tvoid %s(const %s& theEvent);\n\n",theState.GetName().c_str(),theStatechart.GetEventType().c_str());

fprintf(implementationFile,"void %s::%s(const %s& theEvent)\n{\n",theStatechart.GetName().c_str(),theState.GetName().c_str(),theStatechart.GetEventType().c_str());

fprintf(implementationFile,"}\n\n");