glVector diff;
glVector center;

center = absGetStartPoint() + absGetEndPoint();
center /= 2;

diff = center - anchorPoint;
diff = diff.Dir();
diff.RotateDegree(45);
diff *= 15;
diff += anchorPoint;

dc.DrawText(text,diff.xCoord(),diff.yCoord());
