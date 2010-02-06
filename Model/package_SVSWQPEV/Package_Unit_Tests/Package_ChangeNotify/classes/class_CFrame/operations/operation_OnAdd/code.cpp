wxDirDialog dirDlg(this, "Select directory to observe.", "", wxDD_DIR_MUST_EXIST);

if(dirDlg.ShowModal() == wxID_OK)
{
	lstWatches->Append(dirDlg.GetPath());
}