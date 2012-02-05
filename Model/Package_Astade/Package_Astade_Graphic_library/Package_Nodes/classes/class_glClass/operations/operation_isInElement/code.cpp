//~~ bool isInElement(const glVector& position) [glClass] ~~

glVector border = absGetPosition() - position;

return (abs(border.m_x) <= my_XRadius && abs(border.m_y) <= my_YRadius);
