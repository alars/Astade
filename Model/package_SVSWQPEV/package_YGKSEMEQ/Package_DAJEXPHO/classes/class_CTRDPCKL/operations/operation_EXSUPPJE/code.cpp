fprintf(specificationFile,"#ifndef __%s_h\n#define __%s_h\n\n",theStatechart.GetName().c_str(),theStatechart.GetName().c_str());

fprintf(implementationFile,"#include \"%s.h\"\n\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"// Include wxWidgets (to get all event makros)\n");
fprintf(specificationFile,"#include <wx/wx.h>\n\n");


fprintf(specificationFile,"// Include of event ID defines\n");
fprintf(specificationFile,"#include %s\n\n",theStatechart.GetEventType().c_str());

fprintf(specificationFile,"class ImpOf_%s;\n\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"class %s\n{\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"\tpublic:\n");

CodeConstructor(theStatechart);
CodeInitialize(theStatechart);
CodeIsInStateFunction(theStatechart);

fprintf(specificationFile,"\t\twxEvtHandler* GetEventHandler();\n\n");
fprintf(implementationFile,"wxEvtHandler* %s::GetEventHandler()\n{\n\treturn myImplementation;\n}\n\n",theStatechart.GetName().c_str());

CodeActions(theStatechart);
CodeGuards(theStatechart);

fprintf(specificationFile,"\n\tprivate:\n");
fprintf(specificationFile,"\t\tImpOf_%s* myImplementation;\n\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"};\n\n");

fprintf(specificationFile,"class ImpOf_%s : public wxEvtHandler\n{\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"\tpublic:\n");

CodeImpConstructor(theStatechart);
CodeEventTable(theStatechart);
CodeImpInitialize(theStatechart);

fprintf(specificationFile,"\t\t%s& myHandlers;\n\n",theStatechart.GetName().c_str());

CodeStateEnum(theStatechart);

CodeState(theStatechart);
CodeEnterPointer(theStatechart);

CodeHandleFunctions(theStatechart);

CodeEnterFunction(theStatechart);

AdeElementIterator it;
for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeEnterState(theStatechart,*aState);

	}
	delete aElement;
}
fprintf(specificationFile,"\t\tDECLARE_EVENT_TABLE()\n");

fprintf(specificationFile,"};\n\n#endif\n");
