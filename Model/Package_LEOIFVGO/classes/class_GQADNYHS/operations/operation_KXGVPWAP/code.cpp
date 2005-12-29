int theThickness = thickness[classIndex];

if (theThickness < 0)
	return;

if (theThickness > 3)
	return;

int right = GetRightSide(classIndex);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"),wxSOLID));
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));
dc.DrawRectangle(right-5, startY-10, 11, 11);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("WHITE"),1,wxSOLID));
dc.DrawRectangle(right-4, startY-10, 9, 10);
