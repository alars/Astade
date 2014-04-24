wxBitmap theBitmap(dataBase->GetGraphWidth(), dataBase->GetGraphHight(), 32);

wxMemoryDC dc;
dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("LIGHT GREY"),wxSOLID));
dc.Clear();

graphTab->DrawOnDC(dc);

if (wxTheClipboard->Open())
{
	// This data objects are held by the clipboard,
	// so do not delete them in the app.
	wxTheClipboard->SetData( new wxBitmapDataObject(theBitmap) );
	wxTheClipboard->Close();
}
