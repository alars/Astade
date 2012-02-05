//~~ void OnStartMult(wxCommandEvent& event) [glSelfRelation] ~~

wxString aString = wxGetTextFromUser(wxEmptyString, wxS("Start point multiplicity"), myStartMult.myText, myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace(wxS("\t"), wxEmptyString);
aString.Replace(wxS("\n"), wxEmptyString);
aString.Replace(wxS(" "), wxEmptyString);
if (aString != myStartMult.myText)
{
    myStartMult.myText = aString;
    Refresh();
}
