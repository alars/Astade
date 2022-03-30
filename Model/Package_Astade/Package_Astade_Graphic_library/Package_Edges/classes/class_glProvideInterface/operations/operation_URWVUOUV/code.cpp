//~~ void SaveDrawIo(std::ofstream& cr) [glProvideInterface] ~~

glVector diff1 = absDrawnStartPoint - myStartNode.absGetDrawPosition();
glVector diff2 = absDrawnEndPoint - myEndNode.absGetDrawPosition();

cr << "        <mxCell id=\""
   << this
   << "\" value=\"\" style=\"rounded=0;orthogonalLoop=1;jettySize=auto;html=1;exitX="
   << diff1.xCoord() * myStartNode.GetAspectRatio()
   << ";exitY="
   << diff1.yCoord() 
   << ";exitDx=0;exitDy=0;endArrow=none;endFill=0;strokeColor=#FF0000;startSize=0;entryX="
   << diff2.xCoord() * myEndNode.GetAspectRatio()
   << ";entryY="
   << diff2.yCoord() 
   << ";entryDx=0;entryDy=0;\" edge=\"1\" parent=\"1\" source=\"Node:"
   << myStartNode.id
   << "\" target=\"Node:"
   << myEndNode.id
   << "\">\n";
cr << "          <mxGeometry relative=\"1\" as=\"geometry\">\n";
cr << "            <mxPoint as=\"targetPoint\" />\n";
cr << "          </mxGeometry>\n";
cr << "        </mxCell>\n";
