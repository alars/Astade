//~~ void DrawSelfCall(std::ofstream& cr, int eventNumber) [SeqDrawIO] ~~

int xPos = GetRightSide(dataBase->GetSourceIndex(eventNumber));
int yPos = dataBase->GetTime2Y(eventNumber);

cr << "        <mxCell id=\"self:"
   << eventNumber
   << "\" value=\""
   << dataBase->GetLabel(eventNumber)
   << "\" style=\"edgeStyle=orthogonalEdgeStyle;html=1;align=left;spacingLeft=2;endArrow=block;rounded=0;verticalAlign=bottom;fontSize=8;strokeColor=#0000FF;\" edge=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\"-1\" relative=\"1\" as=\"geometry\">\n";
cr << "            <mxPoint x=\""
   << xPos
   << "\" y=\""
   << yPos - 10
   << "\" as=\"sourcePoint\" />\n";
cr << "            <Array as=\"points\">\n";
cr << "              <mxPoint x=\""
   << xPos + 50
   << "\" y=\""
   << yPos - 10
   << "\" />\n";
cr << "              <mxPoint x=\""
   << xPos + 50
   << "\" y=\""
   << yPos
   << "\" />\n";
cr << "            </Array>\n";
cr << "            <mxPoint x=\""
   << xPos + 5
   << "\" y=\""
   << yPos
   << "\" as=\"targetPoint\" />\n";
cr << "            <mxPoint as=\"offset\" />\n";
cr << "          </mxGeometry>\n";
cr << "        </mxCell>\n";

int startY = dataBase->GetTime2Y(eventNumber);
int endY = dataBase->GetTime2Y(dataBase->findReturn(eventNumber));

cr << "        <mxCell id=\"" 
   << "selfexe:" 
   << eventNumber 
   << "\" value=\"\" style=\"html=1;points=[];perimeter=orthogonalPerimeter;fontSize=8;strokeColor=#008000;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << xPos - 5
   << "\" y=\""
   << startY
   << "\" width=\"10\" height=\""
   << endY - startY
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
