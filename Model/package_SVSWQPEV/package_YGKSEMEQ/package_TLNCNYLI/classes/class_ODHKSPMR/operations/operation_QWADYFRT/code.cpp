/* vi: set tabstop=4: */

wxTreeItemId aID = event.GetItem();
AdeModelElement* element = myTree->GetItem(aID);
int type = element->GetType();

switch (type & ITEM_TYPE_MASK)
{
	case ITEM_IS_CPPFILE:
	case ITEM_IS_DOXFILE:
	case ITEM_IS_HFILE:
	case ITEM_IS_MAKE:
		Edit(event);		// Forward event to Edit()
		break;

	case ITEM_IS_ATTRIBUTE:
	case ITEM_IS_RELATION:
	case ITEM_IS_TYPE:
		Features(event);	// Forward event to Features()
		break;

	default:
		event.Skip();		// Skip to next event handler
}
