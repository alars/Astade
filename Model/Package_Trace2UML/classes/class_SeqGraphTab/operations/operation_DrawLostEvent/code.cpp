int start = dataBase->GetSourceIndex(eventNumber);
int stop = dataBase->GetDestinationIndex(eventNumber);
int startPixel;
int stopPixel;
int yPixel = dataBase->GetTime2Y(eventNumber) - 5;

startPixel = dataBase->GetClassMiddle(start);
stopPixel = dataBase->GetClassMiddle(stop);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID ));
dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("RED")), wxSOLID));
dc.DrawCircle(stopPixel, yPixel, 6);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID ));
dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("BLUE")), wxSOLID));
DrawArrow(cr, dc, startPixel, yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber));
