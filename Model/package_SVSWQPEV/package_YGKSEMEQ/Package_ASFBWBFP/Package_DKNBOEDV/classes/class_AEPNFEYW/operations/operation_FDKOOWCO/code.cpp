wxString className = configObject.Read("ClassName");

int xPos;
configObject.Read("xPos",&xPos);

int yPos;
configObject.Read("yPos",&yPos);

return Create(className,parent,wxPoint(xPos,xPos));