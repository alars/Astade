#include <wx/app.h>
#include <wx/cmdline.h>
#include <wx/dir.h>
#include <wx/filename.h>

#ifdef __WXGTK__
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, wxChar **value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, float *value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, long *value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, int *value, const wxString& file = wxEmptyString);
#endif
