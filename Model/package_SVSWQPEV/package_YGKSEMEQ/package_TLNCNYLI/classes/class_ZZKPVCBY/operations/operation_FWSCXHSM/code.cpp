wxTreeItemId newItem = wxTreeCtrl::AppendItem(parent,"loading ...", AstadeLoading::GetLoadingIndex());
AstadeLoading* loadingElement = new AstadeLoading(fileName);
SetItemData(newItem, loadingElement);
loadingElement->SetNeedUpdate();

return newItem;