// -*- C++ -*- generated by wxGlade 0.5 on Tue Dec 23 13:48:51 2008 from C:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\component_KSEQOEET\manual\dialogs.wxg

#include <wx/wx.h>
#include <wx/image.h>

#ifndef GENERATEDSEARCHDIALOG_H
#define GENERATEDSEARCHDIALOG_H

// begin wxGlade: ::dependencies
// end wxGlade


class generatedSearchDialog: public wxDialog {
public:
    // begin wxGlade: generatedSearchDialog::ids
    enum {
        ID_TextToFind = wxID_HIGHEST + 1000,
        ID_OptionCaseSensitive = wxID_HIGHEST + 1001,
        ID_OptionWholeWordsOnly = wxID_HIGHEST + 1002,
        ID_OptionRegularExpression = wxID_HIGHEST + 1003,
        ID_OptionMatchesNOT = wxID_HIGHEST + 1004,
        ID_ScopeEntireModel = wxID_HIGHEST + 1005,
        ID_ScopeActiveComponent = wxID_HIGHEST + 1006,
        ID_LookingForClass = wxID_HIGHEST + 1007,
        ID_LookingForAttribute = wxID_HIGHEST + 1008,
        ID_LookingForOperation = wxID_HIGHEST + 1009,
        ID_LookingForParameter = wxID_HIGHEST + 1010,
        ID_LookingForType = wxID_HIGHEST + 1011,
        ID_LookingForState = wxID_HIGHEST + 1012,
        ID_LookingForUserCode = wxID_HIGHEST + 1013,
        ID_LookingForAll = wxID_HIGHEST + 1014,
        ID_FieldsToSearchName = wxID_HIGHEST + 1015,
        ID_FieldsToSearchType = wxID_HIGHEST + 1016,
        ID_FieldsToSearchDefault = wxID_HIGHEST + 1017,
        ID_FieldsToSearchUserCode = wxID_HIGHEST + 1018,
        ID_FieldsToSearchDescription = wxID_HIGHEST + 1019,
        ID_FieldsToSearchAll = wxID_HIGHEST + 1020,
        IS_StartSearch = wxID_HIGHEST + 1021
    };
    // end wxGlade

    generatedSearchDialog(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: generatedSearchDialog::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: generatedSearchDialog::attributes
    wxStaticBox* sizer_13_staticbox;
    wxStaticBox* sizer_12_staticbox;
    wxStaticBox* sizer_7_staticbox;
    wxStaticBox* sizer_6_staticbox;
    wxStaticText* searchTextLabel;
    wxComboBox* TextToFind;
    wxCheckBox* OptionCaseSensitive;
    wxCheckBox* OptionWholeWordsOnly;
    wxCheckBox* OptionRegularExpression;
    wxCheckBox* OptionMatchesNOT;
    wxRadioButton* ScopeEntireModel;
    wxRadioButton* ScopeActiveComponent;
    wxCheckBox* LookingForClass;
    wxCheckBox* LookingForAttribute;
    wxCheckBox* LookingForOperation;
    wxCheckBox* LookingForParameter;
    wxCheckBox* LookingForType;
    wxCheckBox* LookingForState;
    wxCheckBox* LookingForUserCode;
    wxCheckBox* LookingForAll;
    wxCheckBox* FieldsToSearchName;
    wxCheckBox* FieldsToSearchType;
    wxCheckBox* FieldsToSearchDefault;
    wxCheckBox* FieldsToSearchUserCode;
    wxCheckBox* FieldsToSearchDescription;
    wxCheckBox* FieldsToSearchAll;
    wxButton* StartSearch;
    // end wxGlade
}; // wxGlade: end class


#endif // GENERATEDSEARCHDIALOG_H
