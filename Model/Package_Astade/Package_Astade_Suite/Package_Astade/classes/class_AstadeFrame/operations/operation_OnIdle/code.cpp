//~~ void OnIdle(wxIdleEvent& event) [AstadeFrame] ~~

if (rightMouseClickCount)
    return;

wxTreeItemId aId = AstadeTreeItemBase::GetId4Update();

if (aId.IsOk())
{
    if (myAstadeSearch.isSet(AdeSearch::SearchIsActive))
        SetStatusText(wxS("search..."), 0);
    else
        SetStatusText(wxS("update..."), 0);

    myTree->GetItemObject(aId)->Update();
    event.RequestMore();
}
else
{
    SetStatusText(wxS("done!"), 0);
}

if (itemToClose.IsOk())
{
    myTree->DeleteChildren(itemToClose);
    itemToClose = wxTreeItemId();
}
