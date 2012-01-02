//~~ bool isInElement(const glVector& position) [glEndNode] ~~
glVector border = absGetPosition() - position;

return (border.Mod() <= my_Radius);