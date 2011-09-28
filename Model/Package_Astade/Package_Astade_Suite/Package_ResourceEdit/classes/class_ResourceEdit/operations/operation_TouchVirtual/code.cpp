//~~ void TouchVirtual(wxCommandEvent& event) [ResourceEdit] ~~
if (VirtualField && StaticField && AbstractField && ConstField)
{
    if (VirtualField->IsChecked())
    {
        StaticField->SetValue(false);
    }
    else
    {
        AbstractField->SetValue(false);
    }
}
SetIcon();