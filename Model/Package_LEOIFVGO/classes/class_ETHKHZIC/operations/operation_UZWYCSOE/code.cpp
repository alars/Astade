wxDC* dc = GetDC();
if (!dc)
	return false;

wxCoord w, h;
dc->GetSize(&w, &h);
double scale = (double)mySeqDataBase->GetGraphWidth() / (double)w;
dc->SetUserScale(scale, scale);
mySeqGraphTab->DrawOnDC(*dc);

return true;
