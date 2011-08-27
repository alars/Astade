trcDriver_mytrcStack[++trcDriver_runningObject].runningID = objectID;
trcDriver_mytrcStack[trcDriver_runningObject].runningName = objectName;
trcDriver_mytrcStack[trcDriver_runningObject].runningLevel = traceLevel;
trcDriver_mytrcStack[trcDriver_runningObject].callType = DESTRUCTOR;
