int t = thickness[classIndex];
if (t>MAXDEPTH)
	t=MAXDEPTH;

if (t<=0)
	t=0;

return dataBase->GetClassMiddle(classIndex)+(5*t);