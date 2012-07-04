//~~ void OnTextChange(wxCommandEvent& event) [ReverseEngineerFrame] ~~

wxString sourceText = source->GetValue();

OperationParser aParser(sourceText);

destination->Clear();

if (aParser.ParseSuccessful())
{
	*destination << wxS("Parse successful!\n\n");
	*destination << wxS("Classname    : [") << aParser.className << wxS("]\n");
	*destination << wxS("Returntype   : [") << aParser.returnType << wxS("]\n");
	*destination << wxS("Functionname : [") << aParser.functionName << wxS("]\n");

	if (aParser.isVirtual)
		*destination << wxS("VIRTUAL\n");

	if (aParser.isStatic)
		*destination << wxS("STATIC\n");

	if (aParser.isInline)
		*destination << wxS("INLINE\n");

	if (aParser.isConst)
		*destination << wxS("CONST\n");

	if (!aParser.parameterNames.empty())
	{
		*destination << wxS("Parameter    :\n");
		for (unsigned int i = 0; i < aParser.parameterNames.size(); i++)
		{
			*destination 	<< (int)(i+1)
							<< wxS(". [")
							<< aParser.parameterTypes[i]
							<< wxS("]  [")
							<< aParser.parameterNames[i]
							<< wxS("]  [")
							<< aParser.parameterDefaults[i]
							<< wxS("]\n");
		}
	}

	*destination << wxS("Functionbody : [\n");

	for (unsigned int i = 0; i < aParser.body.GetLineCount(); i++)
		*destination << aParser.body[i] << wxS("\n");

	*destination << wxS("]");
}
else
	*destination << wxS("Parse failed!\n\n");
