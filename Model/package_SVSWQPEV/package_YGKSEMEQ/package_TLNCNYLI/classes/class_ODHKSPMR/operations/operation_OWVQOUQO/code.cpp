wxTreeItemId anId = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(anId);
int type = element->GetType();

switch (type & 0x7F00000)
{
	case ITEM_IS_CLASS:
	case ITEM_IS_STATECHART:
		relationStart = anId;
		AstadeClass::SetRelationSourceName(element->GetLabel());
	break;

	case ITEM_IS_RELATIONS:
		relationStart = myTree->GetItemParent(anId);
		AstadeClass::SetRelationSourceName(myTree->GetItem(myTree->GetItemParent(anId))->GetLabel());
	break;
}
