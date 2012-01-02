//~~ void SetDefaultStyle() [SeqTextTab] ~~
wxTextAttr anAttr = GetDefaultStyle();

wxFont aFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
anAttr.SetFont(aFont);
anAttr.SetTextColour(*wxBLACK);

wxTextCtrl::SetDefaultStyle(anAttr);
