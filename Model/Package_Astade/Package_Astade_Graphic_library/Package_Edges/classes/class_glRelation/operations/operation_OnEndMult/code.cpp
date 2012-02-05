//~~ void OnEndMult(wxCommandEvent& event) [glRelation] ~~

wxString aString = wxGetTextFromUser(wxEmptyString, wxS("End point multiplicity"), myEndMult.myText, myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace(wxS("\t"), wxEmptyString);
aString.Replace(wxS("\n"), wxEmptyString);
aString.Replace(wxS(" "), wxEmptyString);
if (aString != myEndMult.myText)
{
    myEndMult.myText = aString;    
    Refresh();
}
