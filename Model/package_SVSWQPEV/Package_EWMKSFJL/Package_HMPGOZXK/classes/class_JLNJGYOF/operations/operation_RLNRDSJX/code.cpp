glVector sum = glRoundEdge::getEndPointForce();
glVector AnchorForce = myLabel.GetAnchorForce();
AnchorForce /= 2;

AnchorForce += myEndMult.GetAnchorForce();

sum -= AnchorForce;

return sum;
