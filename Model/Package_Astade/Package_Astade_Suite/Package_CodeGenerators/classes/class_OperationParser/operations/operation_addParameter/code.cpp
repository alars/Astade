//~~ void addParameter(char const* p1, char const* p2) [OperationParser] ~~
g_Results->parameterNames.push_back(wxString(&g_Results->paramName, wxConvAuto(), 1));
g_Results->paramName++;
g_Results->parameterTypes.push_back(wxEmptyString);
g_Results->parameterDefaults.push_back(wxEmptyString);