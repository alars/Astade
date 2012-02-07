//~~ wxTreeItemId AppendExistingItem(const wxTreeItemId& parent, const wxFileName& fileName) [AstadeTree] ~~

wxTreeItemId newItem = wxTreeCtrl::AppendItem(parent, wxS("loading ..."), AstadeLoading::GetLoadingIndex());
AstadeLoading* loadingElement = new AstadeLoading(fileName);
SetItemData(newItem, loadingElement);
loadingElement->SetNeedUpdate();

return newItem;
