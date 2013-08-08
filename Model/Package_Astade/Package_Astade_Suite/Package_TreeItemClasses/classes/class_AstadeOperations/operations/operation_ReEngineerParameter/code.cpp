//~~ void ReEngineerParameter(const wxFileName& parent) [AstadeOperations] ~~
if (myOperationParser->parameterNames.empty())
	return;

wxFileName parameters = AdeParameters::CreateNewElement(parent);

for (unsigned int i=0; i < myOperationParser->parameterNames.size(); i++)
{
	AdeParameter::CreateNewElement(parameters,
						myOperationParser->parameterNames[i],
						myOperationParser->parameterTypes[i],
						myOperationParser->parameterDefaults[i]);
}