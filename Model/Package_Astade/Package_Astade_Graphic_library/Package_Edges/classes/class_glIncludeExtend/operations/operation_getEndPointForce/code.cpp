glVector labelForce(myLabel.GetAnchorForce());
labelForce *= -0.5;

return glStraightEdge::getEndPointForce() + labelForce;
