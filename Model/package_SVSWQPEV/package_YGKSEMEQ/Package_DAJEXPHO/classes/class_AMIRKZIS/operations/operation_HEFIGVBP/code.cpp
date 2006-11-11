fprintf(specificationFile,"#ifndef __%s_h\n#define __%s_h\n\n",theStatechart.GetName().c_str(),theStatechart.GetName().c_str());

fprintf(implementationFile,"#include \"%s.h\"\n\n",theStatechart.GetName().c_str());


fprintf(specificationFile,"#define wx__DECLARE_EVT2(evt, id1, id2, fn) (theEvent.GetEventType() == evt && theEvent.GetId() >= id1 && theEvent.GetId() >= id2)\n");
fprintf(specificationFile,"#define wx__DECLARE_EVT1(evt, id, fn) (theEvent.GetEventType() == evt && theEvent.GetId() == id)\n");
fprintf(specificationFile,"#define wx__DECLARE_EVT0(evt, fn) (theEvent.GetEventType() == evt)\n\n");

fprintf(specificationFile,"// Include wxWidgets (to get all event makros)\n");
fprintf(specificationFile,"#include <wx/wx.h>\n\n");


fprintf(specificationFile,"// Include of event ID defines\n");
fprintf(specificationFile,"#include %s\n\n",theStatechart.GetEventType().c_str());

fprintf(specificationFile,"class %s\n{\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"\tpublic:\n");
CodeConstructor(theStatechart);
CodeInitialize(theStatechart);
CodeTakeEvent(theStatechart);

AdeElementIterator it;

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
		CodeIsInStateFunction(theStatechart,*static_cast<AdeState*>(aElement));
	delete aElement;
}

fprintf(specificationFile,"\n\tprotected:\n");

CodeActions(theStatechart);
CodeGuards(theStatechart);

fprintf(specificationFile,"\n\tprivate:\n");

CodeNoState(theStatechart);
CodeState(theStatechart);
CodeEnterPointer(theStatechart);
CodeEnterFunction(theStatechart);

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(theStatechart,*aState);
		CodeEnterState(theStatechart,*aState);

	}
	delete aElement;
}

fprintf(specificationFile,"};\n\n#endif\n");
