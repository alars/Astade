SetSize(wxSize(760, 300));

wxFont aFont(theNormalFont.GetFont());
aFont.SetFamily(wxFONTFAMILY_MODERN);
aFont.SetPointSize(wxNORMAL_FONT->GetPointSize());

theNormalFont.SetFont(aFont);
theErrorFont.SetFont(aFont);
