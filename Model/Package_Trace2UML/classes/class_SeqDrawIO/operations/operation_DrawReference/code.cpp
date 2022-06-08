//~~ void DrawReference(std::ofstream& cr, wxString text, int eventNumber) [SeqDrawIO] ~~

int objectNo = dataBase->GetSourceIndex(eventNumber);
int boxWidth = 60;
int boxHeight = 30;
wxString link;

int pos = text.find("|");
if (pos > 0)
{
    link = text.AfterFirst('|');
    text.erase(pos);
}

int labelLen = text.size() * 4;

if (labelLen > boxWidth)
    boxWidth = labelLen;


cr << "        <mxCell id=\"" 
   << "text:" 
   << eventNumber 
   << "\" value=\""
   << "\" style=\"rounded=0;whiteSpace=wrap;html=1;labelBackgroundColor=default;fontSize=9;fillColor=default;verticalAlign=bottom;strokeColor=none;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassMiddle(objectNo) - boxWidth/2
   << "\" y=\""
   << dataBase->GetTime2Y(eventNumber) - boxHeight + 2
   << "\" width=\""
   << boxWidth
   << "\" height=\""
   << boxHeight
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";

cr << "        <mxCell id=\"" 
   << "state:" 
   << eventNumber 
   << "\" value=\""
   << "ref"
   << "\" style=\"shape=umlFrame;tabPosition=left;html=1;boundedLbl=1;labelInHeader=1;width=30;height=15;align=center;verticalAlign=middle;fontSize=10;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassMiddle(objectNo) - boxWidth/2
   << "\" y=\""
   << dataBase->GetTime2Y(eventNumber) - boxHeight + 2
   << "\" width=\""
   << boxWidth
   << "\" height=\""
   << boxHeight
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";

cr << "        <UserObject id=\"" 
   << "object:" 
   << eventNumber 
   << "\" link=\""
   << link
   << "\" label=\""
   << text
   << "\">\n";
cr << "        <mxCell style=\"rounded=0;whiteSpace=wrap;html=1;labelBackgroundColor=default;fontSize=9;fillColor=none;verticalAlign=bottom;\" vertex=\"1\" parent=\"1\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassMiddle(objectNo) - boxWidth/2
   << "\" y=\""
   << dataBase->GetTime2Y(eventNumber) - boxHeight + 2
   << "\" width=\""
   << boxWidth
   << "\" height=\""
   << boxHeight
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
cr << "        </UserObject>\n";

