fprintf(implementationFile,"\t%s_sm_s_%s,\n", theStatechart.GetName().Lower().c_str(), theState.GetName().Lower().c_str());

fprintf(specificationFile,"\t%s_SM_STATE_ID_%s,\n", theStatechart.GetName().Upper().c_str(), theState.GetName().Upper().c_str());
