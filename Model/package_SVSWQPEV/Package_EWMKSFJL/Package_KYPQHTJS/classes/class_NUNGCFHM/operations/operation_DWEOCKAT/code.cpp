glVector aVector = (absDirection - absGetCenterPoint()).Dir();
aVector *= my_Radius;
return aVector + absGetCenterPoint();