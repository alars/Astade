//~~ void DrawStatechange(std::ofstream& cr, wxString text, int eventNumber) [SeqDrawIO] ~~

int objectNo = dataBase->GetSourceIndex(eventNumber);
int boxWidth = 60;
int boxHeight = 13;

cr << "        <mxCell id=\"" 
   << "state:" 
   << eventNumber 
   << "\" value=\""
   << text
   << "\" style=\"whiteSpace=wrap;html=1;fontSize=8;strokeColor=#0000ff;rounded=1;perimeterSpacing=0;fillColor=#FFFFCC;fontColor=#000000;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassMiddle(objectNo) - boxWidth/2
   << "\" y=\""
   << dataBase->GetTime2Y(eventNumber) - boxHeight - 4
   << "\" width=\""
   << boxWidth
   << "\" height=\""
   << boxHeight
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
