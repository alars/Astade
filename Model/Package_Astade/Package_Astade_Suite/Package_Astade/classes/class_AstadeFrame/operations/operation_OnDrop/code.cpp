//~~ bool OnDrop(const wxPoint& point, const wxArrayString& filenames) [AstadeFrame] ~~

bool retVal = false;

wxTreeItemId anID = myTree->HitTest(point);
if (!anID.IsOk())
	return false;

myTree->SelectItem(anID);
AdeModelElement* dest = myTree->GetItem(anID);
wxFileName parentPath = dest->GetFileName();

for (unsigned int i = 0; i < filenames.GetCount(); i++)
{
	wxFileName aFile(filenames[i]);
	AdeModelElement* anElement = AdeModelElement::CreateNewElement(aFile);
	// does this type of element fit here?
	if (anElement->GetFileName() != parentPath)
	{
		if (dest->CanContain(*anElement))
		{
			wxFileName theNewElement = anElement->CreateCopy(parentPath); // copy the element here
			myTree->AppendItem(anID, theNewElement);
			retVal = true;
		}
		// if the source is a class and the destination is a relations-folder => create a relation
		else if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS &&
				(dest->GetType() & ITEM_TYPE_MASK) == ITEM_IS_RELATIONS)
		{
			wxTreeItemId startId = myTree->GetItemParent(anID);
			wxFileName theNewRelation = AdeRelation::CreateNewElement(myTree->GetItem(startId)->GetFileName(), anElement->GetFileName());
			myTree->AppendItem(anID, theNewRelation);
		}
		else if (dest->GetName() == wxS("manual"))
		{
			wxFileName theNewElement = anElement->CreateCopy(parentPath); // copy the element here
			myTree->AppendItem(anID, theNewElement);
			retVal = true;
		}
		else 
		{
			wxString aString(wxS("The File '") + filenames[i] + wxS("' cannot be dropped here. This type of element does not fit!"));
			wxLogMessage(wxS("%s"), aString.GetData());
		}
	}
	else
	{
		wxString aString(wxS("The File '") + filenames[i] + wxS("' cannot be dropped here. The element cannot be copied to itself!"));
		wxLogMessage(wxS("%s"), aString.GetData());
	}
	delete anElement;
}

return retVal;
