//~~ void SaveDrawIo(std::ofstream& cr) [glFloatingLabel] ~~

cr << "        <mxCell id=\""
   << this
   << "\" value=\""
   << myText.utf8_str()
   << "\" style=\"text;html=1;align=center;verticalAlign=middle;fontSize=10;fontColor=#000000;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << absGetDrawPosition().m_x - 40
   << "\" y=\""
   << absGetDrawPosition().m_y - 8
   << "\" width=\"80\" height=\"16\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
