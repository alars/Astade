#include <wx/string.h>

#ifdef __WXGTK__
bool wxGetResource(const wxString& section, const wxString& entry, wxChar **value, const wxString& file = wxEmptyString);
bool wxGetResource(const wxString& section, const wxString& entry, float *value, const wxString& file = wxEmptyString);
bool wxGetResource(const wxString& section, const wxString& entry, long *value, const wxString& file = wxEmptyString);
bool wxGetResource(const wxString& section, const wxString& entry, int *value, const wxString& file = wxEmptyString);
#endif
