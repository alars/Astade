long sel = lstApps->GetSelection();
if(sel!=wxNOT_FOUND)
{
	lstApps->Delete(sel);
}

txtExt->Clear();
txtApp->Clear();
txtIcon->Clear();