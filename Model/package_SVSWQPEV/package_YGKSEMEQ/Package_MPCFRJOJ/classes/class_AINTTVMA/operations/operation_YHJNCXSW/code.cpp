    // load file in edit and clear undo
    if (!filename.empty()) m_filename = filename;
//     wxFile file (m_filename);
//     if (!file.IsOpened()) return false;
    ClearAll ();
//     long lng = file.Length ();
//     if (lng > 0) {
//         wxString buf;
//         wxChar *buff = buf.GetWriteBuf (lng);
//         file.Read (buff, lng);
//         buf.UngetWriteBuf ();
//         InsertText (0, buf);
//     }
//     file.Close();

    wxStyledTextCtrl::LoadFile(m_filename);

    EmptyUndoBuffer();

    // determine lexer language
    wxFileName fname (m_filename);
    InitializePrefs (DeterminePrefs (fname.GetFullName()));

    return true;
