glVector aVector = (absDirection - absGetDrawPosition()).Dir();
aVector *= my_Radius;
return aVector + absGetDrawPosition();