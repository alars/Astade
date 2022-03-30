//~~ void SaveDrawIo(std::ofstream& cr) [glNote] ~~

cr << "        <mxCell id=\"Node:"
   << id
   << "\" value=\""
   << myLabel.utf8_str()
   << "\" style=\"shape=note;size=20;whiteSpace=wrap;html=1;strokeColor=#008000;align=left;fontSize=10;\" vertex=\"1\" parent=\"1\">\n";
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