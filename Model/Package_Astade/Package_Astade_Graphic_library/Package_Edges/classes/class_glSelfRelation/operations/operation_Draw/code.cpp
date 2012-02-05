//~~ void Draw(wxDC& dc) [glSelfRelation] ~~

int style = wxSOLID;
int width = 1;
wxColor color;
wxColor bgcolor = wxTheColourDatabase->Find(wxS("WHITE"));

switch (type)
{
    case rtAssociation:
    case rtAggregation:
    case rtComposition:
        color =  wxTheColourDatabase->Find(wxS("MEDIUM SEA GREEN"));
        style = wxSOLID;
        break;
        
    case rtDependancy:
    default:
        color =  wxTheColourDatabase->Find(wxS("DARK GREEN"));
        style = wxLONG_DASH;
}

if (isMouseOver())
{
    color = wxTheColourDatabase->Find(wxS("RED"));
    width *= 2;
    dc.SetTextForeground(wxTheColourDatabase->Find(wxS("RED")));
}
else
    dc.SetTextForeground(wxTheColourDatabase->Find(wxS("BLACK")));

dc.SetPen(*wxThePenList->FindOrCreatePen(color, width, style));
dc.SetBrush(*wxTRANSPARENT_BRUSH);

dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
dc.SetPen(*wxThePenList->FindOrCreatePen(color, width, wxSOLID));

switch (type)
{
    case rtDependancy:
        DrawSimpleArrow(dc);
        break;
        
    case rtAggregation:
        dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(bgcolor, wxSOLID));
        DrawDiamond(dc);
        break;
        
    case rtComposition:
        dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(color, wxSOLID));
        DrawDiamond(dc);
        break;
        
    case rtAssociation:
    default:
        /* no arrow */
        break;
}

const_cast<glSelfRelation*>(this)->myLabel.Draw(dc);
const_cast<glSelfRelation*>(this)->myStartMult.Draw(dc);
const_cast<glSelfRelation*>(this)->myEndMult.Draw(dc);

