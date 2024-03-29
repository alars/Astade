//~~ void DrawArrow(std::ofstream& cr, int eventNumber, int startX, int startY, int stopX, int stopY, const wxString& arrowHead, const wxString& label, const wxString& color, bool dashed) [SeqDrawIO] ~~
if (startX < 10)
    startX = 10;

if (startY < 10)
    startY = 10;

if (stopX < 10)
    stopX = 10;

if (stopY < 10)
    stopY = 10;

cr << "        <mxCell id=\"" 
   << "arrow:" 
   << eventNumber 
   << "\" value=\""
   << label
   << "\" style=\"html=1;verticalAlign=bottom;endArrow="
   << arrowHead
   << ";rounded=0;fontSize=8;strokeColor="
   << color;

if (dashed)
    cr << ";endFill=0;dashed=1";

if (startX < stopX)
    cr << ";labelPosition=left;align=left";
else
    cr << ";labelPosition=right;align=right";

cr << ";\" edge=\"1\" parent=\"1\">\n";

if (startX < stopX)
    cr << "          <mxGeometry x=\"-1\" y=\"-1\" relative=\"1\" as=\"geometry\">\n";
else
    cr << "          <mxGeometry x=\"-1\" y=\"1\" relative=\"1\" as=\"geometry\">\n";

cr << "            <mxPoint x=\""
   << startX
   << "\" y=\""
   << startY
   << "\" as=\"sourcePoint\" />\n";
cr << "            <mxPoint x=\""
   << stopX
   << "\" y=\""
   << stopY
   << "\" as=\"targetPoint\" />\n";
cr << "          </mxGeometry>\n";
cr << "        </mxCell>\n";
