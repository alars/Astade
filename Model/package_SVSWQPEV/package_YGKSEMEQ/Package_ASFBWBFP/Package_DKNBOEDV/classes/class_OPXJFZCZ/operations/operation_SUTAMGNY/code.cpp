GrafVector p1 = myStartNode.GetPosition();
GrafVector p2 = myEndNode.GetPosition();

GrafVector r1 = myStartNode.GetBorderPoint(p2);
GrafVector r2 = myEndNode.GetBorderPoint(p1);

GrafVector dif = r2-r1;
double dist = dif.Mod2();

return dif.Dir() * dist / (200000);