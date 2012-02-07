//~~ void setType(char const* p1, char const* p2) [OperationParser] ~~

g_Results->parameterTypes.pop_back();
g_Results->parameterTypes.push_back(wxString(p1, wxConvAuto(), p2 - p1));
