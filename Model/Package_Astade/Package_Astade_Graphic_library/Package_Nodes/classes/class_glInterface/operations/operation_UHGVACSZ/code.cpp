//~~ void SaveDrawIo(std::ofstream& cr) [glInterface] ~~

cr << "        <mxCell id=\"Node:"
   << id
   << "\""
   << " style=\"ellipse;whiteSpace=wrap;html=1;strokeColor=#FF0000;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << absGetDrawPosition().xCoord() - my_Radius
   << "\" y=\""
   << absGetDrawPosition().yCoord() - my_Radius
   << "\" width=\""
   << 2 * my_Radius
   << "\" height=\""
   << 2 * my_Radius
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";

myFloatingLabel.SaveDrawIo(cr);
