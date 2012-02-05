//~~ void Draw(wxDC& dc) [glInterface] ~~

if (isMouseOver())
	dc.SetTextForeground(wxTheColourDatabase->Find(wxS("RED")));
else
	dc.SetTextForeground(wxTheColourDatabase->Find(wxS("BLACK")));

if (myEdges.empty())
{
    if (isMouseOver())
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
    else
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));
    dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("YELLOW"))));
		dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
}
else
{
    if (isMouseOver())
    {
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
    	dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("RED"))));
		dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
    }
    else
    {
    	for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    	{
    		if (dynamic_cast<glProvideInterface*>(*it) != 0)
    		{
	    		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));
    			dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("WHITE"))));
					dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),my_Radius);
     			break;
    		}
    	}
    }
}

const_cast<glInterface*>(this)->myFloatingLabel.Draw(dc);

dc.SetTextForeground(wxTheColourDatabase->Find(wxS("BLACK")));
