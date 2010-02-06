int idx;
if((idx = lstWatches->GetSelection()) != wxNOT_FOUND)
{
	lstWatches->Delete(idx);
}