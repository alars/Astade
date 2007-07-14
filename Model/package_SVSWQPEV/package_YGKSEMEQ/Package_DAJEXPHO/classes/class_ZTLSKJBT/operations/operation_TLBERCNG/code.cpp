fprintf(specificationFile, "\t\t//! \\brief This checks if the machine is in state \"%s\".\n", (const char*)theState.GetName().c_str());
fprintf(specificationFile, "\t\t//! \\return is in state.\n");
fprintf(specificationFile, "\t\tinline bool IsIn%s(){return (theState==&%s::%s);};\n\n", (const char*)theState.GetName().c_str(), (const char*)theStatechart.GetName().c_str(), (const char*)theState.GetName().c_str());
