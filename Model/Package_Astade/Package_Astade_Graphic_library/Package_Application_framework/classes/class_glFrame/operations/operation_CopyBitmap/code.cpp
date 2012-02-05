//~~ void CopyBitmap(wxCommandEvent& event) [glFrame] ~~

wxBitmap theBitmap(xPixelSlider->GetValue(), yPixelSlider->GetValue());

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("WHITE")), wxSOLID));
dc.Clear();

graphicPanel->OnDraw(dc);

dc.SelectObject(wxNullBitmap);
if (wxTheClipboard->Open())
{
	// These data objects are held by the clipboard,
	// so do not delete them in the app.
	wxTheClipboard->SetData(new wxBitmapDataObject(theBitmap));
	wxTheClipboard->Close();
}
