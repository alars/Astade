//~~ void TouchStatic(wxCommandEvent& event) [ResourceEdit] ~~
if (VirtualField && StaticField && AbstractField && ConstField)
    if (StaticField->IsChecked())
    {
        ConstField->SetValue(false);
        VirtualField->SetValue(false);
        AbstractField->SetValue(false);
    }
SetIcon();