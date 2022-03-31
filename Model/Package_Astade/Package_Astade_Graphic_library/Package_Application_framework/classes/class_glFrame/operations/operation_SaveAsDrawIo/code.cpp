//~~ void SaveAsDrawIo() [glFrame] ~~

const wxString& dir = wxFileSelector( wxS("Save Diagram"),
                                      wxEmptyString,
                                      wxEmptyString,
                                      wxEmptyString,
                                      wxS("*.xml"),
                                      wxFD_OVERWRITE_PROMPT | wxFD_SAVE,
                                      this);

if (!dir.empty())
{
    graphicPanel->SaveDrawIo(dir);
}
