//~~ void SaveDrawIo(std::ofstream& cr) [glAssociation] ~~

glVector diff = myStartNode.absGetDrawPosition() - myEndNode.absGetDrawPosition();

cr << "        <mxCell id=\""
   << this
   << "\" value=\"\" style=\"rounded=0;orthogonalLoop=1;jettySize=auto;html=1;exitX="
   << -diff.xCoord() * myStartNode.GetAspectRatio()
   << ";exitY="
   << -diff.yCoord() 
   << ";exitDx=0;exitDy=0;endArrow=none;endFill=0;strokeColor=#FF0000;endSize=10;startSize=0;entryX="
   << diff.xCoord() * myEndNode.GetAspectRatio()
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
