wxTreeItemId aID = myTree->GetSelection(); //get current selection
AdeModelElement* element = myTree->GetItem(aID);

int type = element->GetType(); //Get the item type
bool result = false;

	switch (type & ITEM_TYPE_MASK)
	{

		case ITEM_IS_ATTRIBUTES:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();

				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_ATTRIBUTE)  //Check whether copyType is "Attribute"
				  result = true;
			}
		break;

		case ITEM_IS_CLASSES:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();

				if (((copyType & ITEM_TYPE_MASK) == ITEM_IS_CLASS) || ((copyType & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)) //Check whether copyType is "Class" or a "Statechart"
				  result = true;
			}
		break;

		case ITEM_IS_COMPONENTS:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();

				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_COMPONENT)  //Check whether copyType is "Component"
				  result = true;
			}
		break;

		case ITEM_IS_COMPONENT:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();

				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_CONFIGURATION)  //Check whether copyType is "Configuration"
				  result = true;
			}
		break;

		case ITEM_IS_CONFIGURATION:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();

				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_MAKE)  //Check whether copyType is "Makefile"
				  result = true;
			}
		break;

		case ITEM_IS_OPERATIONS:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_OPERATION)
					result = true;
			}
	 	break;

		case ITEM_IS_PACKAGE:

			if (copySource.IsOk())
		{
			AdeModelElement* copyElement = myTree->GetItem(copySource);
			int copyType = copyElement->GetType();
			if (((copyType & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE) && (copyElement != element))
		        result = true;
		    if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_CLASSES && !dynamic_cast<AdeDirectoryElement*>(element)->GetHasClasses())
				result = true;
		}

		break;

		case ITEM_IS_PARAMETERS:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_PARAMETER)
					result = true;
			}

		break;

		case ITEM_IS_RELATIONS:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if (((copyType & ITEM_TYPE_MASK) == ITEM_IS_RELATION) || ((copyType & ITEM_TYPE_MASK) == ITEM_IS_INRELATION))
					result = true;
			}
		break;

		case ITEM_IS_MODEL:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if (((copyType & ITEM_TYPE_MASK) == ITEM_IS_COMPONENTS) || ((copyType & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE))
					result = true;
			}

		break;

		case ITEM_IS_SEQUENCES:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_SEQUENCE)
					result = true;
			}
		break;

		case ITEM_IS_STATE:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
				    result = true;
			}
		break;

		case ITEM_IS_STATECHART:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_STATE)
				result = true;
			}

		break;

		case ITEM_IS_TYPES:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_TYPE)
				result = true;
			}
	 	break;

		case ITEM_IS_USECASEDIAGRAMS:

			if (copySource.IsOk())
			{
				AdeModelElement* copyElement = myTree->GetItem(copySource);
				int copyType = copyElement->GetType();
				if ((copyType & ITEM_TYPE_MASK) == ITEM_IS_USECASE)
				result = true;
			}
		break;
	}

return result;