wxString sourceText = source->GetValue();

OperationParser aParser(sourceText);

destination->Clear();

if (aParser.ParseSuccessful())
{
	*destination << "Parse successful!\n\n";
	*destination << "Classname    : ["   << aParser.className << "]\n";
	*destination << "Returntype   : ["   << aParser.returnType << "]\n";
	*destination << "Functionname : ["   << aParser.functionName << "]\n";
}
else
	*destination << "Parse failed!\n\n";