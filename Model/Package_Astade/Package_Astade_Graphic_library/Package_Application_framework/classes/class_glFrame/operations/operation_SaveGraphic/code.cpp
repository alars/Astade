//~~ void SaveGraphic(wxCommandEvent& event) [glFrame] ~~

wxBitmap theBitmap(xPixelSlider->GetValue(), yPixelSlider->GetValue());

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("WHITE")), wxSOLID));
dc.Clear();

graphicPanel->OnDraw(dc);

dc.SelectObject(wxNullBitmap);
SaveBitmap(theBitmap);
