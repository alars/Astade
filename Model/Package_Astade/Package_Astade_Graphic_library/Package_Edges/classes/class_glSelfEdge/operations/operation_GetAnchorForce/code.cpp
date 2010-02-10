glVector Anchor = myNode.absGetBorderPoint(absGetPosition());

glVector ancorDist = Anchor-absGetPosition();

double ancorDistMod = ancorDist.Mod();
glVector aForce = ancorDist;
aForce *= ancorDistMod;
aForce *= -0.001;

return aForce;
