Move_Prepare(parentPath);
wxFileName retVal = Move_Do(parentPath);
Move_Complete(parentPath);
return retVal;