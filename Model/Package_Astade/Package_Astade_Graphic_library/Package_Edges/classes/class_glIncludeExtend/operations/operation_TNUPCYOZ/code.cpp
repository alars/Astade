//~~ void SaveDrawIo(std::ofstream& cr) [glIncludeExtend] ~~

glVector diff = myStartNode.absGetDrawPosition() - myEndNode.absGetDrawPosition();

cr << "        <mxCell id=\""
   << this
   << "\" value=\""
   << myLabel.myText.utf8_str()
   << "\" style=\"rounded=0;orthogonalLoop=1;jettySize=auto;html=1;exitX="
   << -diff.xCoord() * 28/56
   << ";exitY="
   << -diff.yCoord() 
   << ";exitDx=0;exitDy=0;endArrow=openThin;endFill=0;strokeColor=#0000FF;dashed=1;endSize=10;startSize=0;entryX="
   << diff.xCoord() * 28/56
   << ";entryY="
   << diff.yCoord() 
   << ";entryDx=0;entryDy=0;\" edge=\"1\" parent=\"1\" source=\"Node:"
   << myStartNode.id
   << "\" target=\"Node:"
   << myEndNode.id
   << "\">\n";
cr << "          <mxGeometry relative=\"1\" as=\"geometry\">\n";
cr << "            <mxPoint as=\"targetPoint\" />\n";
cr << "          </mxGeometry>\n";
cr << "        </mxCell>\n";
