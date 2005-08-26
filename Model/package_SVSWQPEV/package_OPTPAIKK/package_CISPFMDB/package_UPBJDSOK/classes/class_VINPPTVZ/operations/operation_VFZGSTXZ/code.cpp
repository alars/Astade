if (theFilenameList.empty()&&aIterator.theFilenameList.empty())
	return true;

if (aIterator.theFilenameList.empty())
	return false;

if (theFilenameList.empty())
	return false;

return theFilenameList.front()==aIterator.theFilenameList.front();