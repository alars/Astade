#include <wx/frame.h>
#include <wx/statusbr.h>
#include <wx/treectrl.h>
#include <wx/filesys.h>
#include <wx/fs_zip.h>
#include <wx/image.h>
#include <wx/html/helpctrl.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/tbarbase.h>
#include <wx/icon.h>
#include <wx/progdlg.h>
#include <wx/timer.h>
#include <wx/msgdlg.h>



#define ID_WXSTATUSBAR				1001
#define ID_WXTREECTRL				1002
#define ID_SETEDITORS				1003
#define ID_MNU_HELP					1004
#define ID_MNU_INFO					1005
#define ID_ASTADETREE				1006
#define ID_ADDCOMPONENTFOLDER		1007
#define ID_ADDPACKAGE				1008
#define ID_ADDCOMPONENT				1009
#define ID_DELETE					1010
#define ID_ACTIVECONFIGURATION		1011
#define ID_ADDCONFIGURATION			1012
#define ID_FEATURES					1013
#define ID_ADDCLASSES				1014
#define ID_OBJECTMODELDIAGRAM		1015
#define ID_COPYMAKEFILE				1016
#define ID_EDIT						1017
#define ID_MAKE						1018
#define ID_MAKEALL					1019
#define ID_GENERATE					1020
#define ID_REGENERATE				1021
#define ID_ADDTOCOMPONENET			1022
#define ID_ADDCLASS					1023
#define ID_REMOVEFROMCOMPONENET		1024
#define ID_ADDATTRIBUTES			1025
#define ID_ADDOPERATIONS			1026
#define ID_ADDRELATIONS				1027
#define ID_ADDTYPES					1028
#define ID_GENCODE					1029
#define ID_EDITIMPLEMENTATION		1030
#define ID_EDITSPECIFICATION		1031
#define ID_EDITSPECPROLOG			1032
#define ID_EDITIMPPROLOG			1033
#define ID_EDITSPECEPILOG			1034
#define ID_EDITIMPGEPILOG			1035
#define ID_EDITPROLOGEPILOG			1036
#define ID_ADDOPERATION				1037
#define ID_ADDCONSTRUCTOR			1038
#define ID_ADDDESTRUCTOR			1039
#define ID_ADDPARAMETERS			1040
#define ID_ADDATTRIBUTE				1041
#define ID_ADDPARAMETER				1042
#define ID_UP						1043
#define ID_DOWN						1044
#define ID_ADDRELATION				1045
#define ID_COMPLETERELATION			1046
#define TIMER_ID					1047
#define ID_MNU_ABOUT				1048
#define ID_COPY						1049
#define ID_PASTE					1050
