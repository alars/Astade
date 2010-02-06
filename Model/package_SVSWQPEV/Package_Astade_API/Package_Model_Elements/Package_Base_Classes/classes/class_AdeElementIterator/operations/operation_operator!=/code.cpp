if (theFilenameList.empty() && anIterator.theFilenameList.empty())
	return false;

if (anIterator.theFilenameList.empty())
	return true;

if (theFilenameList.empty())
	return true;

return theFilenameList.front() != anIterator.theFilenameList.front();
