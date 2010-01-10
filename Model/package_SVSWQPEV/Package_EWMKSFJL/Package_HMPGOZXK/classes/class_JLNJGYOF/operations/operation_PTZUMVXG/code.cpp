int style = wxSOLID;
int width = 1;
wxColor color = wxTheColourDatabase->Find("MEDIUM SEA GREEN");
wxColor bgcolor = wxTheColourDatabase->Find("WHITE");

if (isMouseOver())
{
    color = wxTheColourDatabase->Find("RED");
    width = 2;
}

switch (type)
{
    case rtDependancy:
    case rtRealization:
        style = wxSHORT_DASH;
        break;

    case rtAssociation:
    case rtAggregation:
    case rtComposition:
    case rtGeneralization:
    default:
        style = wxSOLID;
}

dc.SetPen(*wxThePenList->FindOrCreatePen(color,width,style));
dc.SetTextForeground(color);

DrawArc(dc);

dc.SetPen(*wxThePenList->FindOrCreatePen(color,width,wxSOLID));

switch (type)
{
    case rtDependancy:
        DrawSimpleArrow(dc);
        break;

    case rtRealization:
    case rtGeneralization:
        dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(bgcolor,wxSOLID));
        DrawSolidArrow(dc);
        break;

    case rtAggregation:
        dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(bgcolor,wxSOLID));
        DrawDiamond(dc);
        break;

    case rtComposition:
        dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(color,wxSOLID));
        DrawDiamond(dc);
        break;

    case rtAssociation:
    default:
        /* no arrow */
        break;
}

dc.SetTextForeground(wxTheColourDatabase->Find("BLACK"));

const_cast<glRelation*>(this)->myLabel.Draw(dc);
const_cast<glRelation*>(this)->myStartMult.Draw(dc);
const_cast<glRelation*>(this)->myEndMult.Draw(dc);
