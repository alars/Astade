//~~ void setName(char const* p1, char const* p2) [OperationParser] ~~

g_Results->parameterNames.pop_back();
g_Results->parameterNames.push_back(wxString(p1, wxConvAuto(), p2 - p1));
