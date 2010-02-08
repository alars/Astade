int retVal = lstApps->Append(txtApp->GetValue());
if(retVal>=0)
{
	userapp_t* userapp = new userapp_t();

	userapp->filetype =	txtExt->GetValue();
	userapp->application = txtApp->GetValue();
	userapp->icon = txtIcon->GetValue();
	lstApps->SetClientData(retVal, userapp);
}
