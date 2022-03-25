//~~ void DrawCross(std::ofstream& cr, int eventNumber) [SeqDrawIO] ~~
int objectNo = dataBase->GetDestinationIndex(eventNumber);
int objectBegin = dataBase->GetTime2Y(classEvent[objectNo]);

cr << "        <mxCell id=\"" 
   << "event:" 
   << classEvent[objectNo] 
   << "\" value=\"\" style=\"shape=umlDestroy;whiteSpace=wrap;html=1;strokeWidth=3;fontFamily=Helvetica;fontSize=8;fillColor=#008000;strokeColor=#008000;\" vertex=\"1\" "
   << "parent=\"class:"
   << classEvent[objectNo]
   << "\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassBoxWidth(objectNo)/2 - 8
   << "\" y=\""
   << dataBase->GetTime2Y(eventNumber) - objectBegin + 15
   << "\" width=\"16\" height=\"16\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
