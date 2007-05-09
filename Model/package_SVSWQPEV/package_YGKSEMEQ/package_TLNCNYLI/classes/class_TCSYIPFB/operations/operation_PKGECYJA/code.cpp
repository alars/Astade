long sel = lstApps->GetSelection();
if(sel!=wxNOT_FOUND)
{
	userapp_t* userapp = (userapp_t*)lstApps->GetClientData(sel);

	userapp->filetype =	txtExt->GetValue();
	userapp->application = txtApp->GetValue();
	userapp->icon = txtIcon->GetValue();
}
