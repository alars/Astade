//~~ void SwapOrder(AdeModelElement& anElement) [AdeModelElement] ~~

int typeA = GetType();
int typeB = anElement.GetType();

int orderA = typeA & 0xff;
int orderB = typeB & 0xff;

typeA = (typeA & 0x7fffff00) | orderB;
typeB = (typeB & 0x7fffff00) | orderA;

SetType(typeA);
anElement.SetType(typeB);
