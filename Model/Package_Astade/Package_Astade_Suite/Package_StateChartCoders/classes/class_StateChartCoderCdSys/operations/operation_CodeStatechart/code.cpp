//~~ void CodeStatechart(AdeStatechart& theStatechart) [StateChartCoderCdSys] ~~

//fprintf(implementationFile, "#include \"dbg.h\"\n");
//fprintf(implementationFile, "#include \"prjset.h\"\n\n");

/*fprintf(implementationFile, "// ADD Implementation Prolog!\n\n");*/

fprintf(specificationFile, "#ifndef %s_SM_H\n#define %s_SM_H\n\n", (const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationUsrFile, "#ifndef %s_IMPL_H\n#define %s_IMPL_H\n\n", (const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)theStatechart.GetName().Upper().utf8_str());

CodePrologs(theStatechart);

fprintf(implementationFile, "#include \"../manual/%s_common.h\"\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(implementationFile, "#include \"../manual/%s_impl.c\"\n\n", (const char*)theStatechart.GetName().Lower().utf8_str());

fprintf(specificationUsrFile, "#include \"../manual/%s_common.h\"\n\n", (const char*)theStatechart.GetName().Lower().utf8_str());

fprintf(specificationFile, "#include \"../manual/%s_common.h\"\n", (const char*)theStatechart.GetName().Lower().utf8_str());

CodeEventIds(theStatechart);

// Function Callback Types
fprintf(specificationFile, "/*!@brief EnterState function Callback Type */\n");
fprintf(specificationFile, "typedef void\t(*%s_SM_ENTER) ( \n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile, "\t\tstruct %s_sm_ctrl    \t*sm,\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(specificationFile, "\t\tstruct %s_common_evt \t*evt);\n\n", (const char*)theStatechart.GetName().Lower().utf8_str());

fprintf(specificationFile, "/*!@brief state function Callback Type */\n");
fprintf(specificationFile, "typedef BOOL\t(*%s_SM_STATE) ( \n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile, "\t\tstruct %s_sm_ctrl    \t*sm,\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(specificationFile, "\t\tstruct %s_common_evt \t*evt);\n\n", (const char*)theStatechart.GetName().Lower().utf8_str());

fprintf(specificationFile, "/*!@brief data of the statemachine */\n");
fprintf(specificationFile, "typedef struct %s_sm_ctrl \n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(specificationFile, "{\n");
fprintf(specificationFile, "\t%s_SM_ENTER   \tnext_state;\t //!< Entry to next state\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile, "\t%s_SM_STATE   \tthe_state;\t //!< statefunction\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile, "\t%s_COMMON_USR \tusr; //!< user specific data\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile,"} %s_SM_CTRL;\n\n", (const char*)theStatechart.GetName().Upper().utf8_str());


//fprintf(specificationFile, "\tpublic:\n");
//CodeConstructor(theStatechart);

// CodeNoState(theStatechart);
// CodeStatePointer(theStatechart);
// CodeEnterPointer(theStatechart);

//CodeNotify(theStatechart);

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(anElement);
		CodeStateFunctionPrototype(theStatechart, *aState);
		fprintf(implementationFile, ";\n\n");
		CodeEnterStatePrototype(theStatechart, *aState);
		fprintf(implementationFile, ";\n\n");

	}
	delete anElement;
}

CodeIsInStateData(theStatechart);

CodeEnterFunction(theStatechart);

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(anElement);
		CodeStateFunctionDescription(theStatechart, *aState);
		CodeStateFunctionPrototype(theStatechart, *aState);
		CodeStateFunction(theStatechart,*aState);
		CodeEnterStatePrototype(theStatechart, *aState);
		CodeEnterState(theStatechart, *aState);

	}
	delete anElement;
}

CodeInitialize(theStatechart);
CodeTakeEvent(theStatechart);
CodeIsInStateFunction(theStatechart);

CodeActions(theStatechart);
CodeGuards(theStatechart);

CodeEpilogs(theStatechart);

fprintf(specificationFile, "\n\n#endif\n");
fprintf(specificationUsrFile, "\n\n#endif\n");
