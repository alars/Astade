//~~ void DrawClassBox(std::ofstream& cr, int eventNumber, int objectNumber) [SeqDrawIO] ~~

int endY = eventNumber;
while ((endY < dataBase->GetEventsCount()) &&
       ((dataBase->GetDestinationIndex(endY) != objectNumber) ||
        ((dataBase->GetEventID(endY) != ID_GLOBALDELETE) &&
         (dataBase->GetEventID(endY) != ID_DELETE)
        )
       )
      )
    endY++;

classEvent[objectNumber] = eventNumber;

cr << "        <mxCell id=\"" 
   << "class:" 
   << eventNumber 
   << "\" value=\""
   << dataBase->GetClassName(objectNumber)
   << "\" style=\"shape=umlLifeline;perimeter=lifelinePerimeter;container=1;collapsible=0;recursiveResize=0;rounded=0;shadow=0;strokeWidth=1;strokeColor=#008000;size=30;fontSize=11;\" parent=\"1\" vertex=\"1\">\n";
cr << "          <mxGeometry x=\""
   << dataBase->GetClassMiddle(objectNumber) - (dataBase->GetClassBoxWidth(objectNumber) / 2)
   << "\" y=\""
   << dataBase->GetTime2Y(eventNumber) - 30
   << "\" width=\""
   << dataBase->GetClassBoxWidth(objectNumber) 
   << "\" height=\""
   << dataBase->GetTime2Y(endY-1) - dataBase->GetTime2Y(eventNumber) + 30
   << "\" as=\"geometry\" />\n";
cr << "        </mxCell>\n";
