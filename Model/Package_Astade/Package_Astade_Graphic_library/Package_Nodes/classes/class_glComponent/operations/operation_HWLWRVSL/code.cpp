//~~ void SaveDrawIo(std::ofstream& cr) [glComponent] ~~

cr << "        <mxCell id=\"Node:"
   << id
   << "\" value=\""
   << myLabel.utf8_str()
   << "\" style=\"whiteSpace=wrap;html=1;fontSize=10;strokeColor=#0000FF;verticalAlign=middle;horizontalAlign=middle;\" vertex=\"1\" parent=\"1\">\n";
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


cr << "        <mxCell id=\"pic:"
   << id
   << "\" style=\"shape=component;jettyWidth=8;jettyHeight=4;fontSize=10;strokeColor=#0000FF;\" vertex=\"1\" parent=\"Node:"
   << id
   << "\">\n";
cr << "          <mxGeometry x=\"1\" width=\"16\" height=\"16\" relative=\"1\" as=\"geometry\">\n";
cr << "            <mxPoint x=\"-19\" y=\"3\" as=\"offset\" />\n";
cr << "          </mxGeometry>\n";
cr << "        </mxCell>\n";


//glNode::SaveDrawIo(cr);