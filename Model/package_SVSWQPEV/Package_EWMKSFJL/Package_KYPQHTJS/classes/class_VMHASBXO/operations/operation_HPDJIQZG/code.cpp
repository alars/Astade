glVector aVector = (absDirection - absGetPosition()).Dir();
aVector *= my_Radius;
return aVector + absGetPosition();