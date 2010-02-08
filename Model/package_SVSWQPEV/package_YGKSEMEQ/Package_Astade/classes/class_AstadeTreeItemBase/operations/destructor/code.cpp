if (globalCopySource == this)
	globalCopySource = NULL;

needUpdateList.remove(this); // No update needed  any more ;-)

delete myModelElement;