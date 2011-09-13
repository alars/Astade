#include <wx/bitmap.h>
#include <wx/choicdlg.h>
#include <wx/dataobj.h>
#include <wx/dcmemory.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/frame.h>
#include <wx/image.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/notebook.h>
#include <wx/print.h>
#include <wx/printdlg.h>
#include <wx/textfile.h>

#if !defined(wxS)
#  define wxS(x) wxT(x)
#endif

#define ID_OPEN			20000
#define ID_NOTEBOOK		20001
#define ID_SAVE			20002
#define ID_SAVEGRAPH	20003
#define ID_SAVEAS		20004
#define ID_ABOUT		20005
#define ID_COPYGRAPH	20006
#define ID_PAGESETUP	20007
#define ID_PRINT		20008
#define ID_HELP			20009
#define ID_EDIT			20010
#define ID_EDITBEGIN	20011
#define ID_EDITEND		20211
