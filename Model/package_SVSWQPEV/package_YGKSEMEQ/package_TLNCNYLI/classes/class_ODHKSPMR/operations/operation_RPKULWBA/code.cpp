wxTreeItemId aID = myTree->GetSelection();
wxTreeItemId parentID = myTree->GetItemParent(aID);
AdeModelElement* element = myTree->GetItem(aID);

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) == ITEM_IS_CONFIGURATION)
{
	wxFileName component(myTree->GetItem(aID)->GetFileName());
	component.MakeAbsolute();

	wxFileName command(component.GetPath());

	switch (event.GetId())
	{
		case ID_RUN:
			command.Assign(component.GetPath(), myTree->GetItem(parentID)->GetLabel());
			break;

		default:
			command.Assign(component.GetPath());
	}

	wxShell("\"" + command.GetFullPath() + "\"");

	// To restore Astade.ini that might be changed from the executed Application.
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Flush();
}
else
{
	wxMessageBox("Select the configuration that you want to run first");
}
