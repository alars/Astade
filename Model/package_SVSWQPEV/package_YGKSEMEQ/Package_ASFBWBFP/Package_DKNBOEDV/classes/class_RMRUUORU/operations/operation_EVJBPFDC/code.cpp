wxString aLabel = 	myLabel->GetLineText(0).Trim(false).Trim(true) +
					wxString(" ") +
					myLabel->GetLineText(1).Trim(false).Trim(true) +
					wxString(" ") +
					myLabel->GetLineText(2).Trim(false).Trim(true);

return aLabel;