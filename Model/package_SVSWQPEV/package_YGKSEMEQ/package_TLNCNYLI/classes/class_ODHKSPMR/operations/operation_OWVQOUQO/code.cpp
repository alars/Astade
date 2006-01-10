wxTreeItemId anId = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(anId);
int type = element->GetType();

switch (type & 0x7F00000)
{
	case ITEM_IS_CLASS:
		RelationStart = anId;
	break;

	case ITEM_IS_RELATIONS:
		RelationStart = myTree->GetItemParent(anId);
	break;
}