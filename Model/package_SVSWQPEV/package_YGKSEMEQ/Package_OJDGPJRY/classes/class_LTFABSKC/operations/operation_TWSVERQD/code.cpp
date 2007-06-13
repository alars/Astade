ACRow* aRow = new ACRow;
aRow->myNodes.push_back(new ACStartNode);
aRow->myNodes.back()->SetPosition(wxPoint(20,20));

aRow->myNodes.push_back(new ACActivityNode);
aRow->myNodes.back()->SetPosition(wxPoint(20,50));

aRow->myNodes.push_back(new ACStopNode);
aRow->myNodes.back()->SetPosition(wxPoint(20,80));

return aRow;