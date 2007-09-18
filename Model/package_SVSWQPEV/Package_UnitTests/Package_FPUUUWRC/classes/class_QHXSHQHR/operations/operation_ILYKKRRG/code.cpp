wxString sourceText = source->GetValue();

OperationParser aParser(sourceText);

destination->Clear();

if (aParser.ParseSuccessful())
{
	*destination << "Parse successful!\n\n";
	*destination << "Classname    : ["   << aParser.className << "]\n";
	*destination << "Returntype   : ["   << aParser.returnType << "]\n";
	*destination << "Functionname : ["   << aParser.functionName << "]\n";

	if (aParser.isVirtual)
		*destination << "VIRTUAL\n";

	if (aParser.isStatic)
		*destination << "STATIC\n";

	if (aParser.isInline)
		*destination << "INLINE\n";

	if (aParser.isConst)
		*destination << "CONST\n";

	if (!aParser.parameterNames.empty())
	{
		*destination << "Parameter    :\n";
		for(unsigned int i=0; i<aParser.parameterNames.size(); i++)
		{
			*destination 	<< (int)(i+1)
							<< ". ["
							<< aParser.parameterTypes[i]
							<< "]  ["
							<< aParser.parameterNames[i]
							<< "]\n";
		}
	}

	*destination << "Functionbody : [\n" << aParser.functionBody << "\n]\n";
}
else
	*destination << "Parse failed!\n\n";