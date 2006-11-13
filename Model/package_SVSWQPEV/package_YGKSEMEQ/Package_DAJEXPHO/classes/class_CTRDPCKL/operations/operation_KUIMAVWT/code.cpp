fprintf(specificationFile, "\t\t//! \\brief Constructor.\n");
fprintf(specificationFile, "\t\t%s();\n\n", theStatechart.GetName().c_str());

fprintf(specificationFile, "\t\t//! \\brief Destructor.\n");
fprintf(specificationFile, "\t\tvirtual ~%s();\n\n", theStatechart.GetName().c_str());

fprintf(implementationFile, "%s::%s()\n{\n\tmyImplementation = new ImpOf_%s(*this);\n}\n\n", theStatechart.GetName().c_str(), theStatechart.GetName().c_str(), theStatechart.GetName().c_str());

fprintf(implementationFile, "%s::~%s()\n{\n\tdelete myImplementation;\n}\n\n", theStatechart.GetName().c_str(), theStatechart.GetName().c_str());
