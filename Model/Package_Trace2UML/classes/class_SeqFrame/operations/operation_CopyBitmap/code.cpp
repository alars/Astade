wxBitmap theBitmap(dataBase->GetGraphWidth(), dataBase->GetGraphHeight());

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("WHITE")), wxSOLID));
dc.Clear();

graphTab->DrawOnDC(dc);

dc.SelectObject(wxNullBitmap);
if (wxTheClipboard->Open())
{
	// These data objects are held by the clipboard,
	// so do not delete them in the app.
	wxTheClipboard->SetData(new wxBitmapDataObject(theBitmap));
	wxTheClipboard->Close();
}
