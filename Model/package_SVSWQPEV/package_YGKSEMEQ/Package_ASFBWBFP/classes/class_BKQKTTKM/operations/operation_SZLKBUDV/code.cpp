int w,h;
myUsePanel.GetClientSize(&w,&h);
wxBitmap theBitmap(w,h);

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
dc.Clear();

myUsePanel.OnDraw(dc);


dc.SelectObject(wxNullBitmap);
if (wxTheClipboard->Open())
{
	// These data objects are held by the clipboard,
	// so do not delete them in the app.
	wxTheClipboard->SetData(new wxBitmapDataObject(theBitmap));
	wxTheClipboard->Close();
}
