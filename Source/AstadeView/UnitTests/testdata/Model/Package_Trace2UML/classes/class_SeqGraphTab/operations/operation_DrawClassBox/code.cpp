dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));

wxString name = dataBase->GetClassName(objectNumber);

wxCoord w,h;
dc.GetTextExtent(name, &w, &h);
int width = dataBase->GetClassBoxWidth(objectNumber);

dc.DrawRectangle(dataBase->GetClassMiddle(objectNumber)-width/2,
				dataBase->GetTime2Y(eventNumber)-dataBase->GetClassBoxHight(),
				width,
				dataBase->GetClassBoxHight());

dc.DrawText( name, dataBase->GetClassMiddle(objectNumber)-(w/2), dataBase->GetTime2Y(eventNumber)-(h/2)-(dataBase->GetClassBoxHight()/2) );
