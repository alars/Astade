ACRow* aRow = new ACRow;
aRow->SetPosition(wxPoint(120,50));

aRow->myNodes.push_back(new ACStartNode);
aRow->myNodes.push_back(new ACConnectionNode);
aRow->myNodes.push_back(new ACActivityNode);
aRow->myNodes.push_back(new ACConnectionNode);
aRow->myNodes.push_back(new ACStopNode);

aRow->CalculateNodePositions();

return aRow;