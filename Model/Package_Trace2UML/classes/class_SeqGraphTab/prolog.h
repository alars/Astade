#include <list>
#include <math.h>
#include <wx/dcclient.h>
#include <wx/menu.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/tooltip.h>
#include <cairo.h>

#if !defined(wxS)
#  define wxS(x) wxT(x)
#endif

#define ID_MNU_DELETE		6100

#define MAXDEPTH 14
