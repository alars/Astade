//~~ void DrawComment(std::ofstream& cr, const wxString& text, int timeIndex) [SeqDrawIO] ~~

int yPos = dataBase->GetTime2Y(timeIndex) - 12;

cr << "        <mxCell id=\"comment:"
   << timeIndex
   << "\" value=\""
   << text
   << "\" style=\"endArrow=none;html=1;edgeStyle=orthogonalEdgeStyle;rounded=0;fontSize=8;strokeColor=#FF00FF;fillColor=#f8cecc;dashed=1;align=left;verticalAlign=top;\" edge=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\"-1\" y=\"5\" relative=\"1\" as=\"geometry\">\n";
cr << "            <mxPoint x=\"10\" y=\""
   << yPos
   << "\" as=\"sourcePoint\" />\n";
cr << "            <mxPoint x=\""
   << dataBase->GetGraphWidth()
   << "\" y=\""
   << yPos
   << "\" as=\"targetPoint\" />\n";
cr << "          </mxGeometry>\n";
cr << "        </mxCell>\n";
