#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/filename.h>
#include <wx/button.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>

#define ID_CANCEL         10000
#define ID_SAVEANDEXIT    10001
#define ID_THEBITMAP      10002
#define ID_NAMEEDITFIELD  10003
#define ID_NAME           10004
#define ID_TYPE           10005
#define ID_M_PRIVATE      10006
#define ID_M_PROTECTED    10007
#define ID_M_PUBLIC       10008
#define ID_VISIBILITY     10009
#define ID_CONST          10010
#define ID_VIRTUAL        10011
#define ID_STATIC         10012
#define ID_DEFAULTEDITFIELD 10013
#define ID_DESCRIPTIONEDITFIELD 10014
#define ID_DESCRIPTION    10015
#define ID_AGREGATIONTYPE 10016
#define ID_ABSTRACT       10017
#define ID_IMPLEMENTATION 10018
#define ID_DECLARATIONEDITFIELD 10019
#define ID_ADDITIONALCLASSESEDITFIELD 10020