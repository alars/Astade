wxBitmap theBitmap(dataBase->GetGraphWidth(), dataBase->GetGraphHeight(), 32);

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("LIGHT GREY"), wxSOLID));
dc.Clear();

graphTab->DrawOnDC(dc);

dc.SelectObject(wxNullBitmap);
SaveBitmap(theBitmap);
