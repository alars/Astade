/* vi: set tabstop=4: */

wxString aLabel = myLabel->GetLineText(0).Trim(false).Trim(true) + " ";
if (myLabel->GetNumberOfLines() > 1)
	aLabel += myLabel->GetLineText(1).Trim(false).Trim(true);
aLabel += " ";
if (myLabel->GetNumberOfLines() > 2)
	aLabel += myLabel->GetLineText(2).Trim(false).Trim(true);

return aLabel;
