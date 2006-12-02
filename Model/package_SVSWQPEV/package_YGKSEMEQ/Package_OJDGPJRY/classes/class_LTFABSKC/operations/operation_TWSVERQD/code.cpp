ACRow* aRow = new ACRow;
aRow->myNodes.push_back(new ACStartNode);
aRow->myNodes.push_back(new ACActivityNode);
aRow->myNodes.push_back(new ACStopNode);
return aRow;