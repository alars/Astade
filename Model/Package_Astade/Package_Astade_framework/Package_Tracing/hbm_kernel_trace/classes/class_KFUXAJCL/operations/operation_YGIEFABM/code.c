trcDriver_mytrcEntries[trcDriver_nextWrite].type = CONSTRUCTOR;
trcDriver_mytrcEntries[trcDriver_nextWrite].calledFunction = 0;
trcDriver_mytrcEntries[trcDriver_nextWrite].calledID = objectID;
trcDriver_mytrcEntries[trcDriver_nextWrite].calledName = objectName;
trcDriver_mytrcEntries[trcDriver_nextWrite].callerID = trcDriver_mytrcStack[trcDriver_runningObject].runningID;
trcDriver_mytrcEntries[trcDriver_nextWrite].callerName = trcDriver_mytrcStack[trcDriver_runningObject].runningName;
trcDriver_mytrcEntries[trcDriver_nextWrite++].traceLevel = traceLevel;

trcDriver_nextWrite &= 0xfff;

trcDriver_mytrcStack[++trcDriver_runningObject].runningID = objectID;
trcDriver_mytrcStack[trcDriver_runningObject].runningName = objectName;
trcDriver_mytrcStack[trcDriver_runningObject].runningLevel = traceLevel;
trcDriver_mytrcStack[trcDriver_runningObject].callType = CONSTRUCTOR;
