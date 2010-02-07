glVector Anchor = myGraphicElement->absGetAnchorPoint(this);
glVector ancorDist = Anchor-absCalculateNearestToPoint(Anchor);

double ancorDistMod = ancorDist.Mod();
glVector aForce = ancorDist;
aForce *= ancorDistMod;
aForce *= -0.001;

return aForce;
