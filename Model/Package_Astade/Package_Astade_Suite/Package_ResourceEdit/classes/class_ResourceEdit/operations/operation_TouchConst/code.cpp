//~~ void TouchConst(wxCommandEvent& event) [ResourceEdit] ~~
if (VirtualField && StaticField && AbstractField && ConstField)
    if (ConstField->IsChecked())
    {
        StaticField->SetValue(false);
    }
SetIcon();
