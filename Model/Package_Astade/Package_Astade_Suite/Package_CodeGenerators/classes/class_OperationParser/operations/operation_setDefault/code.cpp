//~~ void setDefault(char const* p1, char const* p2) [OperationParser] ~~

g_Results->parameterDefaults.pop_back();
g_Results->parameterDefaults.push_back(wxString(p1, wxConvAuto(), p2 - p1));
