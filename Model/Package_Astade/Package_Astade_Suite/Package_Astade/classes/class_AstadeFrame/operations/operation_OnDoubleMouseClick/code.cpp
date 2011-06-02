//~~ void OnDoubleMouseClick(wxTreeEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = event.GetItem();
AdeModelElement* element = myTree->GetItem(anID);
int type = element->GetType();

switch (type & ITEM_TYPE_MASK)
{
	case ITEM_IS_CPPFILE:
	case ITEM_IS_DOXFILE:
	case ITEM_IS_HFILE:
	case ITEM_IS_MAKE:
	case ITEM_IS_SEQUENCE:
		Edit(event);		// Forward event to Edit()
		break;

	case ITEM_IS_ATTRIBUTE:
	case ITEM_IS_RELATION:
	case ITEM_IS_TYPE:
	case ITEM_IS_PARAMETER:
	case ITEM_IS_TRANSITION:
	case ITEM_IS_PORT:
	case ITEM_IS_CONNECTION:
		Features(event);	// Forward event to Features()
		break;

	default:
		event.Skip();		// Skip to next event handler
}
