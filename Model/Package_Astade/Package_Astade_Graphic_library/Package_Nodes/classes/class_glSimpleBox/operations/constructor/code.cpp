Refresh();
AddMenuSeparator();
AddMenuFunction("edge",wxCommandEventHandler(glSimpleBox::OnCreateEdge));
mySelfEdge = new glSelfEdge(*parent, *this, glVector(x+30,y+30), 20);
