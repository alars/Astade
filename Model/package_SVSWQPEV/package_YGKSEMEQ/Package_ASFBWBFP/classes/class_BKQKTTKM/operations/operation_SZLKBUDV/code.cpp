int w,h;
myUsePanel.GetClientSize(&w,&h);
wxBitmap theBitmap(w,h);

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
dc.Clear();

myUsePanel.OnDraw(dc);

dc.SelectObject(wxNullBitmap);
myUsePanel.SaveBitmap(theBitmap);
