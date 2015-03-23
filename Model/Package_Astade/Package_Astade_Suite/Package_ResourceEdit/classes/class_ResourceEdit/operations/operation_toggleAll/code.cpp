//~~ void toggleAll(wxCommandEvent& event) [ResourceEdit] ~~
if (triggerEditField && allCheckbox)
{
    if (allCheckbox->IsChecked())
    {
        triggerEditField->SetValue(wxS("ALL"));
        triggerEditField->Enable(false);
    } else {
        triggerEditField->SetValue(wxS(""));
        triggerEditField->Enable(true);
    }
}