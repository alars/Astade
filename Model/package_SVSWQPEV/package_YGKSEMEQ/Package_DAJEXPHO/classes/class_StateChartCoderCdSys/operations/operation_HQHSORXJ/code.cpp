fprintf(specificationFile,"//! \\brief Call this function once, to initialize the state machine.\n");
fprintf(specificationFile,"//! Calling this function a second time will have no effect!\n");
fprintf(specificationFile,"//! This will call all initial actions and enter state \"%s\".\n",theStatechart.GetInitialState().c_str());
fprintf(specificationFile,"//! The actions are called with the event, passed to this function.\n");
fprintf(specificationFile,"//! \\param sm	The statemachine.\n");
fprintf(specificationFile,"//! \\param evt	The event, passed to the initial actions.\n");
fprintf(specificationFile,"extern\tvoid                \t%s_sm_init (\n", theStatechart.GetName().Lower().c_str());
fprintf(specificationFile,"      \t%s_SM_CTRL          \t*sm,\n", theStatechart.GetName().Upper().c_str());
fprintf(specificationFile,"      \tstruct %s_common_evt\t*evt);\n\n", theStatechart.GetName().Lower().c_str());


fprintf(implementationFile,"extern\tvoid                \t%s_sm_init (\n", theStatechart.GetName().Lower().c_str());
fprintf(implementationFile,"      \t%s_SM_CTRL          \t*sm,\n", theStatechart.GetName().Upper().c_str());
fprintf(implementationFile,"      \tstruct %s_common_evt\t*evt)\n", theStatechart.GetName().Lower().c_str());
fprintf(implementationFile,"{\n");

std::set<wxString> aSet;

aSet = theStatechart.GetInitialActions();
fprintf(implementationFile,"\t// Calling the initial actions\n");

for (std::set<wxString>::iterator iter=aSet.begin();iter!=aSet.end();iter++)
	fprintf(implementationFile,"\t%s_impl_%s(sm, evt);\n",
			theStatechart.GetName().Lower().c_str(), (*iter).Lower().c_str());
	//fprintf(implementationFile,"\t%s(theEvent);\n",(*iter).c_str());

fprintf(implementationFile,"\t// Set the initial State function\n");
fprintf(implementationFile,"\tsm->next_state = %s_sm_enter_%s;\n", theStatechart.GetName().Lower().c_str(), theStatechart.GetInitialState().Lower().c_str());

fprintf(implementationFile,"\t// Call the state enter function\n");
fprintf(implementationFile,"\t_enter_state(sm, evt);\n");

fprintf(implementationFile,"}\n\n");
