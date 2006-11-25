int theThickness = thickness[classIndex];

if (theThickness < 0)
	return;

if (theThickness > 3)
	return;

int right = GetRightSide(classIndex);
int startY = dataBase->GetTime2Y(eventNumber);
int length = startY-dataBase->GetTime2Y(eventNumber - 1);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"), 1, wxSOLID));
dc.DrawRectangle(right - 5, startY - length, 11, length - 4);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("WHITE"), 1, wxSOLID));
dc.DrawRectangle(right - 4, startY - length, 9, length - 5);
