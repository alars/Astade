int t = thickness[classIndex];
if (t>4)
	t=4;

if (t<=0)
	t=0;

int table[8] = {0,-5,0,5,10,15,20,25};
return dataBase->GetClassMiddle(classIndex)+table[t];