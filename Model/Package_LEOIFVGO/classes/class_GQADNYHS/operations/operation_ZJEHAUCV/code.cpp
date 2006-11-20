/* vi: set tabstop=4: */

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"), 1, wxSOLID));

wxString name(dataBase->GetClassName(objectNumber));
name.Replace("\\n", "\n", true);

int pos = name.Find(':');
if (pos >= 0 && pos != name.Find("::"))
	dc.SetFont(objectFont);
else
	dc.SetFont(classFont);

wxCoord w, h;
dc.GetTextExtent(name, &w, &h);
int width = dataBase->GetClassBoxWidth(objectNumber);

dc.DrawRectangle(dataBase->GetClassMiddle(objectNumber) - width / 2,
				dataBase->GetTime2Y(eventNumber) - dataBase->GetClassBoxHeight(),
				width,
				dataBase->GetClassBoxHeight());

dc.DrawText(name, dataBase->GetClassMiddle(objectNumber) - w / 2,
			dataBase->GetTime2Y(eventNumber) - h / 2 - dataBase->GetClassBoxHeight() / 2);

dc.SetFont(normalFont);
