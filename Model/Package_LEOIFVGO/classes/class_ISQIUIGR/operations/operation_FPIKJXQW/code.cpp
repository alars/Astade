unsigned int i = 0;
for (i=0; i<itsEvents.size(); i++)
{
	if (itsEvents[i].time > y)
		break;
}
return i;