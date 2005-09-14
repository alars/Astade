if (theFilenameList.empty()&&aIterator.theFilenameList.empty())
	return false;

if (aIterator.theFilenameList.empty())
	return true;

if (theFilenameList.empty())
	return true;

return theFilenameList.front()!=aIterator.theFilenameList.front();