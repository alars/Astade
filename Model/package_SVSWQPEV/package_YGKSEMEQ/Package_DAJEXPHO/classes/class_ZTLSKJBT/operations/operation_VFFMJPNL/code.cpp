fprintf(specificationFile,"\t\t//! \\brief Constructor.\n");
fprintf(specificationFile,"\t\t%s();\n\n",theStatechart.GetName().c_str());

fprintf(implementationFile,"%s::%s()\n{\n\ttheState = &%s::NoState;\n}\n\n",theStatechart.GetName().c_str(),theStatechart.GetName().c_str(),theStatechart.GetName().c_str());