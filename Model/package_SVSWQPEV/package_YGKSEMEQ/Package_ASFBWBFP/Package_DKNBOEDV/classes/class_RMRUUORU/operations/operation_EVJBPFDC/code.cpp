wxString aLabel = myLabel->GetLineText(0) + " " + myLabel->GetLineText(1) + " " +myLabel->GetLineText(2);
aLabel.Trim(true);
aLabel.Trim(false);
return aLabel;