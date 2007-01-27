long sel = lstApps->GetFirstSelected();
lstApps->SetItem(sel, 0, txtExt->GetValue());
lstApps->SetItem(sel, 1, txtApp->GetValue());
lstApps->SetItem(sel, 2, txtIcon->GetValue());