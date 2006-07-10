/* vi: set tabstop=4: */

wxTreeItemId aID = event.GetItem();
AdeModelElement* element = myTree->GetItem(aID);
int type = element->GetType();

switch (type & ITEM_TYPE_MASK)
{
	case ITEM_IS_CPPFILE:
		Edit(event);	//Forwarding event to Edit.
	break;

	case ITEM_IS_DOXFILE:
		Edit(event);
	break;

	case ITEM_IS_HFILE:
		Edit(event);
	break;

	case ITEM_IS_MAKE:
		Edit(event);
	break;
}

