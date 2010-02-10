glVector diff = myNode.absGetPosition() - absGetPosition();
diff = diff.Dir();
diff *= my_Radius;

if (theLabel == &myEndMult)
    diff = diff.RotateDegree(90);

if (theLabel == &myStartMult)
    diff = diff.RotateDegree(-90);

return absGetPosition() - diff;
