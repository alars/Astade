wxTextAttr anAttr = GetDefaultStyle();

wxFont aFont(anAttr.GetFont());
aFont.SetFamily(wxFONTFAMILY_MODERN);
aFont.SetPointSize(wxNORMAL_FONT->GetPointSize());
anAttr.SetFont(aFont);
anAttr.SetTextColour(*wxBLACK);

wxTextCtrl::SetDefaultStyle(anAttr);
