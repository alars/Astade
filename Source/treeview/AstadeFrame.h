//---------------------------------------------------------------------------
//
// Name:        AstadeFrame.h
// Author:      
// Created:     12.03.2005 16:28:19
// Copyright:
//
//---------------------------------------------------------------------------
#ifndef __ASTADEFRAME_HPP_
#define __ASTADEFRAME_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif



////Header Include Start
#include <wx/toolbar.h>
#include <wx/treectrl.h>
#include <wx/statusbr.h>
#include <wx/html/helpctrl.h>
////Header Include End

#include <wx/frame.h>
#include <wx/filename.h>
#include "astadetree.h"
#include "Astade.h"

////GUI Control ID Start
#define ID_WXTOOLBAR             1001
#define ID_WXSTATUSBAR           1002
#define ID_SETMOULEPATH          1003
#define ID_WXTREECTRL            1004
#define ID_DELETE                1005
#define ID_ADDPACKAGE            1006
#define ID_ADDCOMPONENTFOLDER    1007
#define ID_ADDCOMPONENT          1008
#define ID_ADDCLASS              1009
#define ID_ADDATTRIBUTE          1010
#define ID_ADDOPERATION          1011
#define ID_ADDCONFIGURATION      1012
#define ID_SETATTRIBEDITOR       1013
#define ID_FEATURES              1014
#define ID_CODE                  1015
#define ID_ADDCONSTRUCTOR        1016
#define ID_SETCODEEDITOR         1017
#define ID_ATTRIBFEATURES        1018
#define ID_ADDATTRIBUTES         1019
#define ID_ADDOPERATIONS         1020
#define ID_ADDPARAMETERS         1021
#define ID_ADDCLASSES            1022
#define ID_ADDPARAMETER          1023
#define ID_UP                    1024
#define ID_DOWN                  1025
#define ID_SETPARAMEDITOR        1026
#define ID_PARAMFEATURES         1027
#define ID_SETOPEDITOR           1028
#define ID_OPFEATURES            1029
#define ID_ADDDESTRUCTOR         1030
#define ID_ADDRELATION           1031
#define ID_COMPLETERELATION      1032
#define ID_ADDRELATIONS          1033
#define ID_OBJECTMODELDIAGRAM    1034
#define ID_SETOMDVIEWER          1035
#define ID_SETRELATIONEDITOR     1036
#define ID_RELATIONFEATURES      1037
#define ID_INRELATIONFEATURES    1038
#define ID_SETCLASSEDITOR        1039
#define ID_CLASSFEATURES         1040
#define ID_GENCODE               1041
#define ID_SETCODER              1042
#define ID_EDITIMPLEMENTATION    1043
#define ID_EDITSPECIFICATION     1044
#define ID_EDITPROLOGEPILOG      1045
#define ID_EDITSPECPROLOG        1046
#define ID_EDITIMPPROLOG         1047
#define ID_EDITSPECEPILOG        1048
#define ID_EDITIMPGEPILOG        1049
#define ID_ACTIVECONFIGURATION   1050
#define ID_EDITFILE              1051
#define ID_ADDTYPES              1052
#define ID_ADDTYPE               1053
#define ID_MNU_HELP              1054
#define ID_MNU_INFO              1055
////GUI Control ID End


////Dialog Style Start
	#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX |  wxCLOSE_BOX
////Dialog Style End

DECLARE_APP(Astade)

class AstadeFrame : public wxFrame
{
public:
    DECLARE_EVENT_TABLE()
public:
    AstadeFrame();
    virtual ~AstadeFrame();
public:
	CAstadeTree *myTree;
	wxStatusBar *myStatusBar;
	wxMenuBar *myMenuBar;
	wxMenu *myCustomizeMenu;
	wxMenu *myHelpMenu;
 
public:
    void AstadeFrameClose(wxCloseEvent& event);
	void OnBeginDrag(wxTreeEvent& event);
	void OnRightMouseClick(wxTreeEvent& event);
	void OnSelChanged(wxTreeEvent& event);
	void OnActivate(wxTreeEvent& event);
	void ExpandNode(wxTreeEvent& event);
	void CollapseNode(wxTreeEvent& event);
	void OnBeginEdit(wxTreeEvent& event);
	void OnEndEdit(wxTreeEvent& event);
	void SetModulePath(wxCommandEvent& event);
	void SizeChanged(wxSizeEvent& event);
	void DisplayHelp(wxCommandEvent& event){theHelp.Display("treeview");};
	void DisplayInfo(wxCommandEvent& event){theHelp.Display("info");};
	void AddComponentFolder(wxCommandEvent& event);
	void AddComponent(wxCommandEvent& event);
	void AddConfiguration(wxCommandEvent& event);
	void ActiveConfiguration(wxCommandEvent& event);
	void AddPackage(wxCommandEvent& event);
	void AddClass(wxCommandEvent& event);
	void AddClasses(wxCommandEvent& event);
	void AddRelations(wxCommandEvent& event);
	void AddAttribute(wxCommandEvent& event);
	void AddType(wxCommandEvent& event);
	void AddAttributes(wxCommandEvent& event);
	void AddTypes(wxCommandEvent& event);
	void AddOperation(wxCommandEvent& event);
	void AddConstructor(wxCommandEvent& event);
	void AddDestructor(wxCommandEvent& event);
	void AddOperations(wxCommandEvent& event);
	void AddParameters(wxCommandEvent& event);
	void AddParameter(wxCommandEvent& event);
	void SetClassEditor(wxCommandEvent& event);
	void SetAttributeEditor(wxCommandEvent& event);
	void SetParameterEditor(wxCommandEvent& event);
	void SetRelationEditor(wxCommandEvent& event);
	void SetOpEditor(wxCommandEvent& event);
	void SetCodeEditor(wxCommandEvent& event);
	void SetCoder(wxCommandEvent& event);
	void SetOMDViewer(wxCommandEvent& event);
	void Delete(wxCommandEvent& event);
	void DeleteOther(wxString& myName);
	void Up(wxCommandEvent& event);
	void Down(wxCommandEvent& event);
	void DeleteDir(wxString& path);
	void CallClassEditor(wxCommandEvent& event);
	void CallAttributeEditor(wxCommandEvent& event);
	void CallRelationEditor(wxCommandEvent& event);
	void CallInRelationEditor(wxCommandEvent& event);
	void CallParameterEditor(wxCommandEvent& event);
	void CallOpEditor(wxCommandEvent& event);
	void CallCodeEditor(wxCommandEvent& event);
	void CallFileEditor(wxCommandEvent& event);
	void CallSpecificationEditor(wxCommandEvent& event);
	void CallImplementationEditor(wxCommandEvent& event);
	void CallImpPrologEditor(wxCommandEvent& event);
	void CallImpEpilogEditor(wxCommandEvent& event);
	void CallSpecPrologEditor(wxCommandEvent& event);
	void CallSpecEpilogEditor(wxCommandEvent& event);
	void CallCoder(wxCommandEvent& event);
	void DoStartRelation(wxCommandEvent& event);
	void DoCompleteRelation(wxCommandEvent& event);
	void ShowOMD(wxCommandEvent& event);
	void WriteDesktopIni(wxFileName dir,int iType,wxString name);
	wxTreeItemId AddNamedItem(wxTreeItemId aID,wxString guessedName,int iType);
	void UpdateText(wxTreeItemId aID);
	void CreateNewFolder(wxTreeItemId aID, bool useGUID=true);
	void CreateNewFile(wxTreeItemId aID);
	wxString GUID();
	int selectIcon(int iType);
	wxString Encode(wxString input);
	wxString Decode(wxString input);

private:
    wxImageList myImageList;
    wxString RootName;
    wxFileName ClassEditor;
    wxFileName AttributeEditor;
    wxFileName RelationEditor;
    wxFileName ParameterEditor;
    wxFileName OperationEditor;
    wxFileName CodeEditor;
    wxFileName OMDViewer;
    wxFileName Coder;
    wxTreeItemId RelationStart;
    wxHtmlHelpController theHelp;
};


#endif
 
 
 
 
