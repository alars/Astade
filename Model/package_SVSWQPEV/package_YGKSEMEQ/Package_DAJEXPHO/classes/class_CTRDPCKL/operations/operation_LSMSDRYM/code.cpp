fprintf(specificationFile, "\t\t//! \\brief Constructor.\n");
fprintf(specificationFile, "\t\tImpOf_%s(%s& handler);\n\n", theStatechart.GetName().c_str(), theStatechart.GetName().c_str());

fprintf(specificationFile, "\t\t//! \\brief Destructor.\n");
fprintf(specificationFile, "\t\tvirtual ~ImpOf_%s();\n\n", theStatechart.GetName().c_str());

fprintf(implementationFile, "ImpOf_%s::ImpOf_%s(%s& handler) : myHandlers(handler)\n{\n\ttheState = ID_noState;\n", theStatechart.GetName().c_str(), theStatechart.GetName().c_str(), theStatechart.GetName().c_str());
fprintf(implementationFile, "\tnextState = 0;\n}\n\n");

fprintf(implementationFile, "ImpOf_%s::~ImpOf_%s()\n{\n}\n\n", theStatechart.GetName().c_str(), theStatechart.GetName().c_str());
