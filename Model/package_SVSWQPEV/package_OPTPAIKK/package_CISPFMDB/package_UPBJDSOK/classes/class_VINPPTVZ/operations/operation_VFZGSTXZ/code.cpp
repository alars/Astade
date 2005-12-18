if (theFilenameList.empty() && anIterator.theFilenameList.empty())
	return true;

if (anIterator.theFilenameList.empty())
	return false;

if (theFilenameList.empty())
	return false;

return theFilenameList.front() == anIterator.theFilenameList.front();
