//~~ void CodeStateFunctionDescription(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~

fprintf(implementationFile, "\n/*! \\brief The function of %s. \n", (const char*)theState.GetName().c_str()); 
fprintf(implementationFile, "   %s\n", (const char*)theState.GetDescription().c_str());
fprintf(implementationFile, "*/\n");
