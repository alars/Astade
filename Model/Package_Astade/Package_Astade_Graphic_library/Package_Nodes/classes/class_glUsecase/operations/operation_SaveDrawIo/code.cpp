//~~ void SaveDrawIo(std::ofstream& cr) [glUsecase] ~~

cr << "        <mxCell id=\"Node:"
   << id
   << "\" value=\""
   << myLabel
   << "\" style=\"ellipse;whiteSpace=wrap;html=1;fillColor=#E6E6E6;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << absGetDrawPosition().xCoord() - my_XRadius
   << "\" y=\""
   << absGetDrawPosition().yCoord() - my_YRadius
   << "\" width=\""
   << 2 * my_XRadius
   << "\" height=\""
   << 2 * my_YRadius
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";

glNode::SaveDrawIo(cr);