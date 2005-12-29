int theThickness = thickness[classIndex];

if (theThickness < 0)
	return;

if (theThickness > 3)
	return;

int right = GetRightSide(classIndex);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"),wxSOLID));
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));
dc.DrawRectangle(right-5, startY, 11, 11);
