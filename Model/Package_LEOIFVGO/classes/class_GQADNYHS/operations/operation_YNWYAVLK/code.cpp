int theThickness = thickness[classIndex];

if (theThickness < 0)
	return;

if (theThickness >= MAXDEPTH)
	return;

int right = GetRightSide(classIndex);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(_T("WHITE")), wxSOLID));
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(_T("SEA GREEN")), 1, wxSOLID));
dc.DrawRectangle(right - 5, startY, 11, 6);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(_T("WHITE")), 1, wxSOLID));
dc.DrawRectangle(right - 4, startY + 1, 9, 5);
