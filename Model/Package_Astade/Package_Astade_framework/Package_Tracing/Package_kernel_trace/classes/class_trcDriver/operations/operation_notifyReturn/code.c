switch (trcDriver_mytrcStack[trcDriver_runningObject].callType)
{
	case FUNCTIONCALL:
	trcDriver_mytrcEntries[trcDriver_nextWrite].type = FUNCTIONRETURN;
	trcDriver_mytrcEntries[trcDriver_nextWrite].calledFunction = 0;
	trcDriver_mytrcEntries[trcDriver_nextWrite].calledID = trcDriver_mytrcStack[trcDriver_runningObject].runningID;
	trcDriver_mytrcEntries[trcDriver_nextWrite].calledName = trcDriver_mytrcStack[trcDriver_runningObject].runningName;
	trcDriver_mytrcEntries[trcDriver_nextWrite].traceLevel = trcDriver_mytrcStack[trcDriver_runningObject--].runningLevel;
	trcDriver_mytrcEntries[trcDriver_nextWrite].callerID = trcDriver_mytrcStack[trcDriver_runningObject].runningID;
	trcDriver_mytrcEntries[trcDriver_nextWrite++].callerName = trcDriver_mytrcStack[trcDriver_runningObject].runningName;
	trcDriver_nextWrite &= 0xfff;
	break;
	
	case DESTRUCTOR:
	trcDriver_mytrcEntries[trcDriver_nextWrite].type = DESTRUCTOR;
	trcDriver_mytrcEntries[trcDriver_nextWrite].calledFunction = 0;
	trcDriver_mytrcEntries[trcDriver_nextWrite].calledID = trcDriver_mytrcStack[trcDriver_runningObject].runningID;
	trcDriver_mytrcEntries[trcDriver_nextWrite].calledName = trcDriver_mytrcStack[trcDriver_runningObject].runningName;
	trcDriver_mytrcEntries[trcDriver_nextWrite].traceLevel = trcDriver_mytrcStack[trcDriver_runningObject--].runningLevel;
	trcDriver_mytrcEntries[trcDriver_nextWrite].callerID = trcDriver_mytrcStack[trcDriver_runningObject].runningID;
	trcDriver_mytrcEntries[trcDriver_nextWrite++].callerName = trcDriver_mytrcStack[trcDriver_runningObject].runningName;
	trcDriver_nextWrite &= 0xfff;
	break;
	
	default:
		trcDriver_runningObject--;
	break;
}

