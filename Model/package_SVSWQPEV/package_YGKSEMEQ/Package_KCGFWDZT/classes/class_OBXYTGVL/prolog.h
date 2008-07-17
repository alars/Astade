#include <wx/wx.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>

#if !defined(wxS)
#  define wxS(x) wxT(x)
#else
#  undef wxS
#  define wxS(x) x
#endif
