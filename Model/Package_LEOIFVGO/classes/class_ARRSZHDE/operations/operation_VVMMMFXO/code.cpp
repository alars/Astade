wxBitmap theBitmap(dataBase->GetGraphWidth(), dataBase->GetGraphHeight());

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
dc.Clear();

graphTab->DrawOnDC(dc);

dc.SelectObject(wxNullBitmap);
SaveBitmap(theBitmap);
