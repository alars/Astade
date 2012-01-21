//~~ bool isInElement(const glVector& position) [glInvisible] ~~

glVector border = absGetPosition() - position;
return border.Mod() <= (my_Radius + 6);
