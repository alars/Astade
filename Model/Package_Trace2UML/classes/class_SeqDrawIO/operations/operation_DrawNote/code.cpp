//~~ void DrawNote(std::ofstream& cr, wxString text, int eventNumber) [SeqDrawIO] ~~
int yPixel = dataBase->GetTime2Y(eventNumber);
int maxheight = yPixel - dataBase->GetTime2Y(eventNumber-1);

int objectNo = dataBase->GetSourceIndex(eventNumber);
int boxWidth = 60;
int boxHeight = maxheight - 4;

int labelLen = text.size() * 4;

if (labelLen > boxWidth)
    boxWidth = labelLen;
    
if (boxWidth > 90)
    boxWidth = 90;

cr << "        <mxCell id=\"" 
   << "note:" 
   << eventNumber 
   << "\" value=\""
   << text
   << "\" style=\"shape=note2;boundedLbl=1;whiteSpace=wrap;html=1;size=10;verticalAlign=middle;align=center;perimeterSpacing=0;spacingRight=10;fontSize=9;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassMiddle(objectNo) - boxWidth/2
   << "\" y=\""
   << yPixel - boxHeight - 4
   << "\" width=\""
   << boxWidth
   << "\" height=\""
   << boxHeight
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
