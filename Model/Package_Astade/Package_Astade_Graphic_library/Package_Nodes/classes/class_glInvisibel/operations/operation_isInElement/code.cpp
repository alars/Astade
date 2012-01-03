//~~ bool isInElement(const glVector& position) [glInvisibel] ~~
glVector border = absGetPosition() - position;

return (border.Mod() <= (my_Radius+6));