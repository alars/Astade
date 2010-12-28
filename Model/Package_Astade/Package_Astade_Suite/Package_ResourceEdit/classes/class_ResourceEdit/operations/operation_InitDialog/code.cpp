//~~ void InitDialog(wxInitDialogEvent& event) [ResourceEdit] ~~
/* vi: set tabstop=4: */

wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);

int elementType;
bool hasTraceLevel = false;
bool canCCoded = false;
bool manual = false;
bool lib = false;
bool hasNamespace = false;

wxConfigBase::Get()->Read("Astade/ManualClass",&manual);
wxConfigBase::Get()->Read("Astade/LibClass",&lib);

if (wxConfigBase::Get()->Read("Astade/Type", &elementType));
{
	switch(elementType & ITEM_TYPE_MASK)
	{
		case ITEM_IS_PORT:
			AddIconSizer(topsizer, true, false, false, false, false, false);
            AddCheckboxSizer(topsizer, false, false, false, false, false, false, false, false, false, true, true);
            AddDelegateSizer(topsizer);
			AddDescriptionSizer(topsizer);
        break;
        
        case ITEM_IS_PACKAGE:
            hasNamespace = true;
		case ITEM_IS_COMPONENTS:
		case ITEM_IS_COMPONENT:
		case ITEM_IS_CONFIGURATION:
			AddIconSizer(topsizer, true, false, false, false, false, false);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_TRANSITION:
			AddIconSizer(topsizer, false, false, false, false, false, false);
			AddTransitionSizer(topsizer);
			AddActionSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_STATE:
			AddIconSizer(topsizer, true, false, false, true, false, false);
			AddEntryExitSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_STATECHART:
			AddIconSizer(topsizer, true, false, false, false, false, false);
			AddInitialStateSizer(topsizer);
			AddActionSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_CLASS:
			AddIconSizer(topsizer, true, false, false, false, (!(lib || manual)), false);
			AddBaseClassesSizer(topsizer);
			AddDescriptionSizer(topsizer);
            canCCoded = true;
		break;

		case ITEM_IS_TYPE:
			AddIconSizer(topsizer, true, false, false, false, false, false);
			AddTypedefSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_OPERATION:
			hasTraceLevel = true;
			if (elementType & ITEM_IS_NORMALOP)
			{
				AddIconSizer(topsizer, true, true, false, false, false, false);
				AddCheckboxSizer(topsizer, true, true, true, true, true, true, false);
				AddConstraintSizer(topsizer);
				AddReturnDescriptionSizer(topsizer);
				AddDescriptionSizer(topsizer);
			}
			else if (elementType & ITEM_IS_DEST)
			{
				AddIconSizer(topsizer, false, false, false, false, false, false);
				AddCheckboxSizer(topsizer, false, true, false, false, true, true, false);
				AddDescriptionSizer(topsizer);
			}
			else
			{
				AddIconSizer(topsizer, false, false, false, false, false, false);
				AddCheckboxSizer(topsizer, false, false, false, false, true, true, true);
				AddInitializerSizer(topsizer);
				AddDescriptionSizer(topsizer);
			}
			AddDeprecatedSizer(topsizer);
		break;

		case ITEM_IS_ATTRIBUTE:
			AddIconSizer(topsizer, true, true, true, false, false, true);
            
			AddCheckboxSizer(topsizer, true, false, true, false, true, false, false);
			AddConstraintSizer(topsizer);
			AddDescriptionSizer(topsizer);
			AddDeprecatedSizer(topsizer);
		break;

		case ITEM_IS_RELATION:
			AddIconSizer(topsizer, true, false, true, false, true, false);
			AddRelationSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		case ITEM_IS_PARAMETER:
			AddIconSizer(topsizer, true, true, true, false, false, false);
			AddCheckboxSizer(topsizer, false, false, false, false, false, false, false, true, true);
			AddConstraintSizer(topsizer);
			AddDescriptionSizer(topsizer);
		break;

		default:
			AddIconSizer(topsizer, false, false, false, false, false, false);
			topsizer->AddStretchSpacer();
		break;
	}
    AddButtonSizer(topsizer,hasTraceLevel,canCCoded,hasNamespace);
	SetIcon();
}
topsizer->SetMinSize(wxSize(450, 350));
SetSizerAndFit(topsizer);
