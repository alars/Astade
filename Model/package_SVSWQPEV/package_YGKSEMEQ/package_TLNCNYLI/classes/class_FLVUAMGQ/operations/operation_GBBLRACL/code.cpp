if (needUpdateList.empty())
	return wxTreeItemId();

wxTreeItemId ret = needUpdateList.front()->GetId();
needUpdateList.pop_front();
return ret;