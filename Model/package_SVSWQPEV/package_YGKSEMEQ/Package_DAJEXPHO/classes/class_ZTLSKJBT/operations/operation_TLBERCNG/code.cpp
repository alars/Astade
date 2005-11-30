fprintf(specificationFile,"\t\t//! \\brief This checks, wether the machine is in state %s.\n",theState.GetName().c_str());
fprintf(specificationFile,"\t\t//! \\return Is in state.\n");
fprintf(specificationFile,"\t\tinline bool IsIn%s(){return (theState==&%s::%s);};\n\n",theState.GetName().c_str(),theStatechart.GetName().c_str(),theState.GetName().c_str());

