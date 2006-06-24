dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),1,wxSOLID));
int w,h;
GetSize(&w,&h);

for (int i = 10; i < w; i+=20)
{
	for (int j = 10; j < h; j+=20)
	{
		dc.DrawCircle(i,j,2);
		std::set<GrafNode*> aSet;
		GrafVector dest = GrafVector(i,j) + (GetForce(GrafVector(i,j),aSet) * 200);
		dc.DrawLine(i,j,dest.xCoord(),dest.yCoord());
	}
}