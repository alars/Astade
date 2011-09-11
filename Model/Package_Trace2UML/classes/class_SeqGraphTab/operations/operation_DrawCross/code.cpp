dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(color),2,wxSOLID ));

dc.DrawLine(x+8, y+8, x-8, y-8);
dc.DrawLine(x+8, y-8, x-8, y+8);