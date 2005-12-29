dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));

dc.DrawRectangle(dataBase->GetClassMiddle(objectNumber)-dataBase->GetClassBoxWidth()/2,
				dataBase->GetTime2Y(eventNumber)-dataBase->GetClassBoxHight(),
				dataBase->GetClassBoxWidth(),
				dataBase->GetClassBoxHight());

wxString name = dataBase->GetClassName(objectNumber);

wxCoord w,h;

dc.GetTextExtent(name, &w, &h);
dc.DrawText( name, dataBase->GetClassMiddle(objectNumber)-(w/2), dataBase->GetTime2Y(eventNumber)-(h/2)-(dataBase->GetClassBoxHight()/2) );
