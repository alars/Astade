/* vi: set tabstop=4: */

SetMinSize(wxSize(450, 350));
wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
SetSizer(topsizer);

int elementType;
bool hasTraceLevel = false;
bool canCCoded = false;

if (wxConfigBase::Get()->Read("Astade/Type", &elementType));
{
	switch(elementType & ITEM_TYPE_MASK)
	{
		case ITEM_IS_COMPONENTS:
		case ITEM_IS_COMPONENT:
		case ITEM_IS_CONFIGURATION:
		case ITEM_IS_PACKAGE:
			AddIconSizer(topsizer, true, false, false, false, false);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_TRANSITION:
			AddIconSizer(topsizer, false, false, false, false, false);
			AddTransitionSizer(topsizer);
			AddActionSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_STATE:
			AddIconSizer(topsizer, true, false, false, true, false);
			AddEntryExitSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_STATECHART:
			AddIconSizer(topsizer, true, false, false, false, false);
			AddInitialStateSizer(topsizer);
			AddActionSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_CLASS:
			AddIconSizer(topsizer, true, false, false, false, true);
			AddBaseClassesSizer(topsizer);
			AddDescriptionSizer(topsizer);
            canCCoded = true;
		break;

		case ITEM_IS_TYPE:
			AddIconSizer(topsizer, true, false, false, false, false);
			AddTypedefSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_OPERATION:
			hasTraceLevel = true;
			if (elementType & ITEM_IS_NORMALOP)
			{
				AddIconSizer(topsizer, true, true, false, false, false);
				AddCheckboxSizer(topsizer, true, true, true, true, true, true, false);
				AddReturnDescriptionSizer(topsizer);
				AddDescriptionSizer(topsizer);
			}
			else if (elementType & ITEM_IS_DEST)
			{
				AddIconSizer(topsizer, false, false, false, false, false);
				AddCheckboxSizer(topsizer, false, true, false, false, true, true, false);
				AddDescriptionSizer(topsizer);
			}
			else
			{
				AddIconSizer(topsizer, false, false, false, false, false);
				AddCheckboxSizer(topsizer, false, false, false, false, true, true, true);
				AddInitializerSizer(topsizer);
				AddDescriptionSizer(topsizer);
			}
			AddDeprecatedSizer(topsizer);
		break;

		case ITEM_IS_ATTRIBUTE:
			AddIconSizer(topsizer, true, true, true, false, false);
			AddCheckboxSizer(topsizer, true, false, true, false, true, false, false);
			AddDescriptionSizer(topsizer);
			AddDeprecatedSizer(topsizer);
		break;

		case ITEM_IS_RELATION:
			AddIconSizer(topsizer, true, false, true, false, true);
			AddRelationSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_PARAMETER:
			AddIconSizer(topsizer, true, true, true, false, false);
			AddDescriptionSizer(topsizer);
		break;

		default:
			AddIconSizer(topsizer, false, false, false, false, false);
			topsizer->AddStretchSpacer();
		break;
	}
    AddButtonSizer(topsizer,hasTraceLevel,canCCoded);
	SetIcon();
}

Layout();
