wxString sourceText = source->GetValue();

OperationParser aParser(sourceText);

destination->Clear();

if (aParser.ParseSuccessful())
{
	*destination << "Parse successful!\n\n";
	*destination << "Declaration:\n"   << aParser.GetDeclaration() << "\n\n";
	*destination << "Parameterlist:\n" << aParser.GetParameterlist() << "\n\n";
	*destination << "Buddy:\n"         << aParser.GetBuddy() << "<END>\n\n";
}
else
	*destination << "Parse failed!\n\n";