//~~ void notify_function_call(int traceLevel, char* objectName, char* functionName, void* objectID) [trcDriver] ~~
trcDriver_mytrcEntries[trcDriver_nextWrite].type = FUNCTIONCALL;
trcDriver_mytrcEntries[trcDriver_nextWrite].calledFunction = functionName;
trcDriver_mytrcEntries[trcDriver_nextWrite].calledID = objectID;
trcDriver_mytrcEntries[trcDriver_nextWrite].calledName = objectName;
trcDriver_mytrcEntries[trcDriver_nextWrite].callerID = trcDriver_mytrcStack[trcDriver_runningObject].runningID;
trcDriver_mytrcEntries[trcDriver_nextWrite].callerName = trcDriver_mytrcStack[trcDriver_runningObject].runningName;
trcDriver_mytrcEntries[trcDriver_nextWrite++].traceLevel = traceLevel;

trcDriver_nextWrite &= 0xfff;

trcDriver_mytrcStack[++trcDriver_runningObject].runningID = objectID;
trcDriver_mytrcStack[trcDriver_runningObject].runningName = objectName;
trcDriver_mytrcStack[trcDriver_runningObject].runningLevel = traceLevel;
trcDriver_mytrcStack[trcDriver_runningObject].callType = FUNCTIONCALL;
