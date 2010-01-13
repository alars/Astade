// load file in edit and clear undo
if (!filename.empty())
	m_filename = filename;

ClearAll ();
wxStyledTextCtrl::LoadFile(m_filename);

EmptyUndoBuffer();

// determine lexer language
wxFileName fname (m_filename);
InitializePrefs (DeterminePrefs (fname.GetFullName()));

return true;
