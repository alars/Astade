//~~ void setReturnType(char const* p1, char const* p2) [OperationParser] ~~

g_Results->returnType = wxString(p1, wxConvAuto(), p2 - p1);
