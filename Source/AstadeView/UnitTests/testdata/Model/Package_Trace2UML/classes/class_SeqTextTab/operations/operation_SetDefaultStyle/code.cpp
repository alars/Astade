wxTextAttr anAttr = GetDefaultStyle();

wxFont aFont(anAttr.GetFont());
aFont.SetFamily(wxFONTFAMILY_MODERN);
anAttr.SetFont(aFont);
anAttr.SetTextColour(*wxBLACK);

wxTextCtrl::SetDefaultStyle(anAttr);