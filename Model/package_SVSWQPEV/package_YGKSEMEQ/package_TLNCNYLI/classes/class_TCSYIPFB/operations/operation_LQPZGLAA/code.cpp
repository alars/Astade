long sel = lstApps->GetSelection();
if(sel!=wxNOT_FOUND)
{
	userapp_t* userapp = (userapp_t*)lstApps->GetClientData(sel);

	txtExt->SetValue(userapp->filetype);
	txtApp->SetValue(userapp->application);
	txtIcon->SetValue(userapp->icon);
}