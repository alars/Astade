int w,h;
GetSize(&w,&h);

configObject.Write("xPos",m_Position.xCoord());
configObject.Write("yPos",m_Position.yCoord());
configObject.Write("Label",GetLabel());
