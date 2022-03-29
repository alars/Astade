//~~ void SaveDrawIo(std::ofstream& cr) [glActor] ~~

cr << "        <mxCell id=\"Node:"
   << id
   << "\" value=\""
   << myLabel.utf8_str()
   << "\" style=\"shape=umlActor;verticalLabelPosition=bottom;verticalAlign=top;html=1;fillColor=#FFFFFF;strokeColor=#FF0000;fontSize=10;spacing=-2;\" vertex=\"1\" parent=\"1\">\n";
cr << "       <mxGeometry x=\""
   << absGetDrawPosition().xCoord() - 15
   << "\" y=\""
   << absGetDrawPosition().yCoord() - 20
   << "\" width=\"18\" height=\"40\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";

//glNode::SaveDrawIo(cr);