Move_Prepare(parentPath);
bool retVal = Move_Do(parentPath);
if (retVal)
	Move_Complete(parentPath);
else
	Move_Rollback();

return retVal;
