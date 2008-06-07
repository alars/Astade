int index = 0;
int distance = 999999;
for (int i = 0; i < GetClassCount(); ++i)
{
	int thisDistance = x-GetClassMiddle(i);
	if (abs(thisDistance-40) < abs(distance))
	{
		distance = thisDistance;
		index = i;
	}
}

int depth = (9+distance)/5;
unsigned int event = GetTimeFromY(y);

wxString ret;

if (depth == thicknessCache[event][index]+1)
    depth--;
else if (depth > thicknessCache[event][index])
    depth = -1;

if (event < itsEvents.size() && depth > 0)
{
    int search = event;
    while (search > 0 && thicknessCache[search][index] >= depth)
        search--;
    ret = itsEvents[search+1].label;
}

return ret;