glVector sum = glRoundEdge::getEndPointForce();
glVector AnchorForce = myLabel.GetAnchorForce();

AnchorForce /= 2;

sum -= AnchorForce;

return sum;
