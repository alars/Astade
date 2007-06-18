ACRow* aRow = new ACRow;
aRow->myNodes.push_back(new ACStartNode);
aRow->myNodes.back()->SetPosition(wxPoint(120,50));

aRow->myNodes.push_back(new ACActivityNode);
aRow->myNodes.back()->SetPosition(wxPoint(120,100));

aRow->myNodes.push_back(new ACStopNode);
aRow->myNodes.back()->SetPosition(wxPoint(120,150));

return aRow;