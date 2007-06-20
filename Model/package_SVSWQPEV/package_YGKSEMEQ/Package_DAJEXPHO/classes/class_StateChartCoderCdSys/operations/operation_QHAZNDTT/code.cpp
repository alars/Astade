fprintf(implementationFile,"static\tBOOL\t%s_sm_s_%s (\n", theStatechart.GetName().Lower().c_str(), theState.GetName().Lower().c_str());
fprintf(implementationFile,"\t%s_SM_CTRL   \t*sm,\n", theStatechart.GetName().Upper().c_str());
fprintf(implementationFile,"\t%s_COMMON_EVT\t*evt)", theStatechart.GetName().Upper().c_str());