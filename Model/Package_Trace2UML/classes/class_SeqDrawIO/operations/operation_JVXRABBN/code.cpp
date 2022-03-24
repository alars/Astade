//~~ void DrawExecution(std::ofstream& cr, int xPosition, int startEvent, int stopEvent) [SeqDrawIO] ~~

int startY = dataBase->GetTime2Y(startEvent) - 5;
int endY = dataBase->GetTime2Y(stopEvent) - 5;

cr << "        <mxCell id=\"" 
   << "exe:" 
   << startEvent 
   << "\" value=\"\" style=\"html=1;points=[];perimeter=orthogonalPerimeter;fontSize=8;strokeColor=#008000;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << xPosition
   << "\" y=\""
   << startY
   << "\" width=\"10\" height=\""
   << endY - startY
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
