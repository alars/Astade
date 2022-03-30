//~~ void SaveDrawIo(std::ofstream& cr) [glFloatingLabel] ~~

cr << "        <mxCell id=\""
   << this
   << "\" value=\""
   << myText.utf8_str()
   << "\" style=\"text;html=1;align=center;verticalAlign=middle;fontSize=10;fontColor=#000000;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << absGetDrawPosition().m_x
   << "\" y=\""
   << absGetDrawPosition().m_y
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
