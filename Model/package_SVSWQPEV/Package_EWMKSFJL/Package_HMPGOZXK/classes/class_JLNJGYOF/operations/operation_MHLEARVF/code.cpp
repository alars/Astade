glVector start = absGetStartPoint();
glVector end = absGetEndPoint();

glVector anchorPoint;

if (theLabel==&myLabel)
{
    glVector diff = end - start;
    diff *= 0.5;

    glVector widthVector = (diff.Rotate90Degree()).Dir();
    widthVector *= -width;

    anchorPoint = start + diff + widthVector;
}
else if (theLabel==&myStartMult)
{
    anchorPoint = start;
}
else if (theLabel==&myEndMult)
{
    anchorPoint = end;
}
else
{
    /* unknown label */
}

return anchorPoint;
