//~~ void Draw(wxDC& dc) [glRelation] ~~

int style = wxSOLID;
int width = 1;
wxColor color;
wxColor bgcolor = wxTheColourDatabase->Find(wxS("WHITE"));

switch (type)
{
    case rtRealization:
        color = wxTheColourDatabase->Find(wxS("BLUE"));
        style = wxLONG_DASH;
        break;

    case rtAssociation:
    case rtAggregation:
    case rtComposition:
        color = wxTheColourDatabase->Find(wxS("MEDIUM SEA GREEN"));
        style = wxSOLID;
        break;
        
    case rtGeneralization:
        color = wxTheColourDatabase->Find(wxS("BLUE"));
        style = wxSOLID;
        break;
        
    case rtDependancy:
    default:
        color = wxTheColourDatabase->Find(wxS("DARK GREEN"));
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

DrawArc(dc);

dc.SetPen(*wxThePenList->FindOrCreatePen(color, width, wxSOLID));

switch (type)
{
    case rtDependancy:
        DrawSimpleArrow(dc);
        break;

    case rtRealization:
    case rtGeneralization:
        dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(bgcolor, wxSOLID));
        DrawSolidArrow(dc);
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

const_cast<glRelation*>(this)->myLabel.Draw(dc);
const_cast<glRelation*>(this)->myStartMult.Draw(dc);
const_cast<glRelation*>(this)->myEndMult.Draw(dc);
