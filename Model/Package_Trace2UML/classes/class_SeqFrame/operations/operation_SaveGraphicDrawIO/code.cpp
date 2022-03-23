//~~ void SaveGraphicDrawIO(wxCommandEvent& event) [SeqFrame] ~~

wxString savefilename = wxFileSelector( wxS("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxS("draw io files (*.xml)|*.xml"),
                                        wxFD_SAVE,
                                        this);

if (savefilename.empty())
    return;

SeqDrawIO(dataBase).writeFile(savefilename);
