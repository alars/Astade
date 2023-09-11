//~~ void SaveDrawIo(std::ofstream& cr) [glActivity] ~~

cr << "        <mxCell id=\"Node:"
   << id
   << "\" value=\""
   << myLabel.utf8_str()
   << "\" style=\"shape=step;perimeter=stepPerimeter;whiteSpace=wrap;html=1;fixedSize=1;spacingLeft=0;spacingRight=0;spacing=22;fillColor=#fff2cc;\" vertex=\"1\" parent=\"1\">\n";
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