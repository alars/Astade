glVector sum = glRoundEdge::getStartPointForce();
glVector AnchorForce = myLabel.GetAnchorForce();

AnchorForce /= 2;

sum -= AnchorForce;

return sum;
