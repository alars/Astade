#if wxUSE_FILEDLG
    // return if no change
    if (!Modified())
		return true;

    // get filname
    if (!m_filename) {
        wxFileDialog dlg (this, wxS("Save file"), wxEmptyString, wxEmptyString, wxS("Any file (*)|*"),
                          wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
        if (dlg.ShowModal() != wxID_OK) return false;
        m_filename = dlg.GetPath();
    }

    // save file
    return SaveFile (m_filename);
#else
    return false;
#endif // wxUSE_FILEDLG
