if (m_MouseOver)
{
	dc.SetBrush(*wxLIGHT_GREY);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
}
else
{
	dc.SetBrush(*wxLIGHT_GREY);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));
}

dc.DrawCircle(myPosition,10);