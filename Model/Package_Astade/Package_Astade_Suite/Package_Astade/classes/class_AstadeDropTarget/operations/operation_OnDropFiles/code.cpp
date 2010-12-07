//~~ bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames) [AstadeDropTarget] ~~
return m_frame->OnDrop(wxPoint(x, y), filenames);