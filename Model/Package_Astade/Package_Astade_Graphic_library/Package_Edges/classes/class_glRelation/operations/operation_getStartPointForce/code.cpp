glVector sum = glRoundEdge::getStartPointForce();
glVector AnchorForce = myLabel.GetAnchorForce();
AnchorForce /= 2;

AnchorForce += myStartMult.GetAnchorForce();

sum -= AnchorForce;

return sum;
