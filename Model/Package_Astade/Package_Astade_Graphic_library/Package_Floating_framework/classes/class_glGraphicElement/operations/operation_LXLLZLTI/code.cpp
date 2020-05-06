//~~ void OnMetaData(wxCommandEvent& event) [glGraphicElement] ~~
wxString aString = wxGetTextFromUser(wxEmptyString, wxS("Meta data"), metaData, myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace(wxS("\t"), wxS(" "));
aString.Replace(wxS("\n"), wxS(" "));
aString.Replace(wxS("  "), wxS(" "));

if (metaData != aString)
{
    metaData = aString;
    glChangeNotifier::Notify();
}