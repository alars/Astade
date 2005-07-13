//---------------------------------------------------------------------------
//
// Name:        ResourceEdit.h
// Author:      
// Created:     25.04.2005 19:19:46
// Copyright:
//
//---------------------------------------------------------------------------
#ifndef __RECOURCEEDIT_HPP_
#define __RECOURCEEDIT_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif



////Header Include Start
////Header Include End

#include <wx/dialog.h>
#include <wx/string.h>

//Compatibility for 2.4.x code
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

////GUI Control ID Start

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

////GUI Control ID End

////Dialog Style Start
#define THIS_DIALOG_STYLE  wxCAPTION 
////Dialog Style End

class ResourceEdit : public wxDialog
{
public:
    ResourceEdit( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("ResourceEdit"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~ResourceEdit();
public:
  ////GUI Control Declaration Start

  ////GUI Control Declaration End

private:
    DECLARE_EVENT_TABLE()
    int m_iType;
    wxString m_oName;
    wxTextCtrl* NameEditField;   
    wxTextCtrl* DefaultEditField;   
    wxTextCtrl* TypeEditField;
    wxTextCtrl* DescriptionEditField;
    wxCheckBox* ConstField;
    wxCheckBox* VirtualField;
    wxCheckBox* StaticField;
    wxCheckBox* AbstractField;
    wxComboBox* AgregationType;
    wxComboBox* Multiplicity;
    wxComboBox* Implementation;
    wxStaticText* TextMultiplicity;
    wxStaticText* TextImplementation;
    
    wxRadioButton* m_private;  
    wxRadioButton* m_protected;  
    wxRadioButton* m_public;  

public:
    wxString file;
    wxStaticBitmap* myBitmap;
    
    void ResourceEditClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void InitDialog(wxInitDialogEvent& event);

	void Cancel(wxCommandEvent& event);
	void UncheckStatic(wxCommandEvent& event);
	void UncheckVirtual(wxCommandEvent& event);
	void CheckVirtual(wxCommandEvent& event);
	void ChangeIcon(wxCommandEvent& event);
	void Save(wxCommandEvent& event);
	wxString Encode(wxString input);
	wxString Decode(wxString input);
	wxString RelatedClass;
	wxArrayString getMultiplicityImplementations();
	wxArrayString getRelationImplementations();

};


#endif
 
 
 
 
