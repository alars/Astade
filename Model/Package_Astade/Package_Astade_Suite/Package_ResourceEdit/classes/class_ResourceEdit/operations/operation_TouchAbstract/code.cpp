//~~ void TouchAbstract(wxCommandEvent& event) [ResourceEdit] ~~
if (VirtualField && StaticField && AbstractField && ConstField)
    if (AbstractField->IsChecked())
    {
        VirtualField->SetValue(true);
        StaticField->SetValue(false);
    }
SetIcon();
