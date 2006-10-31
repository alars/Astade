wxDC* dc = GetDC();
if (!dc)
	return false;

mySeqGraphTab->DrawOnDC(*dc);

return true;
