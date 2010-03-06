long aType = GetType();
aType &= 0xffffff00;
aType |= orderNumber;
SetType(aType);
