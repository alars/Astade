//~~ int GetLeftSide(int classIndex) [SeqDrawIO] ~~
int t = thickness[classIndex];
if (t>MAXDEPTH)
	t=MAXDEPTH;

if (t<=0)
	t=0;

int table[15] = {0,-5,0,5,10,15,20,25,30,35,40,45,50,55,60};
return dataBase->GetClassMiddle(classIndex)+table[t];