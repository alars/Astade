//~~ void InitDialog(wxInitDialogEvent& event) [ResourceEdit] ~~
/* vi: set tabstop=4: */

wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);

int elementType;
bool hasTraceLevel = false;
bool canCCoded = false;
bool manual = false;
bool lib = false;
bool hasNamespace = false;

wxConfigBase::Get()->Read(wxS("Astade/ManualClass"), &manual);
wxConfigBase::Get()->Read(wxS("Astade/LibClass"), &lib);

if (wxConfigBase::Get()->Read(wxS("Astade/Type"), &elementType))
{
    switch(elementType & ITEM_TYPE_MASK)
    {
        case ITEM_IS_PORT:
            AddIconSizer(topsizer, true, false, false, false, false, false);
            AddCheckboxSizer(topsizer, this, false, false, false, false, false, false, false, false, false, true);
            AddDelegateSizer(topsizer);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_CONNECTION:
            AddIconSizer(topsizer, false, false, false, false, false, false);
            AddConnectionSizer(topsizer);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_PACKAGE:
            hasNamespace = true;
        case ITEM_IS_COMPONENTS:
        case ITEM_IS_COMPONENT:
        case ITEM_IS_CONFIGURATION:
            AddIconSizer(topsizer, true, false, false, false, false, false);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_TRANSITION:
            AddIconSizer(topsizer, false, false, false, false, false, false);
            AddTransitionSizer(topsizer);
            AddActionSizer(topsizer,this);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_STATE:
            AddIconSizer(topsizer, true, false, false, true, false, false);
            AddEntryExitSizer(topsizer);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_STATECHART:
            AddIconSizer(topsizer, true, false, false, false, false, false);
            AddNotebookSizer(topsizer);
            AddInitialStateSizer(featurePanelSizer,featurePanel);
            AddActionSizer(featurePanelSizer,featurePanel);
            AddDescriptionSizer(featurePanelSizer,featurePanel);
        break;

        case ITEM_IS_CLASS:
            AddIconSizer(topsizer, true, false, false, false, (!(lib || manual)), false);
            AddNotebookSizer(topsizer);
            AddBaseClassesSizer(featurePanelSizer,featurePanel);
            AddDescriptionSizer(featurePanelSizer,featurePanel);
            canCCoded = !lib;
        break;

        case ITEM_IS_TYPE:
            AddIconSizer(topsizer, true, false, false, false, false, false);
            AddTypedefSizer(topsizer);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_OPERATION:
            hasTraceLevel = true;
            if (elementType & ITEM_IS_NORMALOP)
            {
                AddIconSizer(topsizer, true, true, false, false, false, false);
                AddNotebookSizer(topsizer);
                AddCheckboxSizer(featurePanelSizer, featurePanel, true, true, true, true, true, true, false);
                AddConstraintSizer(featurePanelSizer,featurePanel);
                AddReturnDescriptionSizer(featurePanelSizer,featurePanel);
                AddDescriptionSizer(featurePanelSizer,featurePanel);
            }
            else if (elementType & ITEM_IS_DEST)
            {
                AddIconSizer(topsizer, false, false, false, false, false, false);
                AddCheckboxSizer(topsizer, this, false, true, false, false, true, true, false);
                AddDescriptionSizer(topsizer,this);
            }
            else
            {
                AddIconSizer(topsizer, false, false, false, false, false, false);
                AddCheckboxSizer(topsizer, this, false, false, false, false, true, true, true);
                AddInitializerSizer(topsizer,this);
                AddDescriptionSizer(topsizer,this);
            }
            AddDeprecatedSizer(topsizer);
        break;

        case ITEM_IS_ATTRIBUTE:
            AddIconSizer(topsizer, true, true, true, false, false, true);

            AddCheckboxSizer(topsizer, this, true, false, true, false, true, false, false);
            AddConstraintSizer(topsizer,this);
            AddDescriptionSizer(topsizer,this);
            AddDeprecatedSizer(topsizer);
        break;

        case ITEM_IS_RELATION:
            AddIconSizer(topsizer, true, false, true, false, true, false);
            AddRelationSizer(topsizer);
            AddDescriptionSizer(topsizer,this);
        break;

        case ITEM_IS_PARAMETER:
            AddIconSizer(topsizer, true, true, true, false, false, false);
            AddCheckboxSizer(topsizer, this, false, false, false, false, false, false, false, true, true);
            AddConstraintSizer(topsizer,this);
            AddDescriptionSizer(topsizer,this);
        break;

        default:
            AddIconSizer(topsizer, false, false, false, false, false, false);
            topsizer->AddStretchSpacer();
        break;
    }
    AddButtonSizer(topsizer,hasTraceLevel,canCCoded,hasNamespace);
    SetIcon();
}
topsizer->SetMinSize(wxSize(450, 550));
SetSizerAndFit(topsizer);

if (triggerEditField && allCheckbox)
{
    if (allCheckbox->IsChecked())
        triggerEditField->Enable(false);
    else
        triggerEditField->Enable(true);
}
