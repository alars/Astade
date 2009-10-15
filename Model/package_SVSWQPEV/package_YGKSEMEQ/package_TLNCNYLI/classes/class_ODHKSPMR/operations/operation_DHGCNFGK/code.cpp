GetToolBar()->EnableTool(ID_TOOL_BUILD, !newValue);
GetToolBar()->EnableTool(ID_TOOL_RUN, !newValue);
GetToolBar()->EnableTool(ID_TOOL_FASTRUN, !newValue);
GetToolBar()->EnableTool(ID_STOP_BUILD, newValue);
if (!newValue)
	theMakeProcess = NULL;
