stream << "digraph G {" << std::endl;
stream << "\tNOSTATE [shape=circle label=\"\" width=0.2 style=filled fillcolor=black color=black];" << std::endl;

stream << "\tNOSTATE->"
	<< theStatechart.GetInitialState().c_str()
	<< " [label=\""
	<< theStatechart.GetDiagramLabel().c_str()
	<< "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
	<< std::endl;

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		stream << "\t"
			<< aState->GetName().c_str()
			<< " [label=\"{"
			<< aState->GetDiagramLabel().c_str()
			<< "}\", shape=Mrecord, color=darkviolet, fontname=arial, fontsize=12];"
			<< std::endl;

		AdeElementIterator it2;
		for (it2 = aState->begin(); it2 != aState->end(); ++it2)
		{
			AdeModelElement* anElement2 = it2.CreateNewElement();
			if ((anElement2->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
			{
				AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement2);
				if (aTransition->IsNormalTransition() &&
					!aTransition->GetDestination().empty())
					stream << "\t"
						<< aState->GetName().c_str()
						<< "->"
						<< aTransition->GetDestination().c_str()
						<< " [label=\""
						<< aTransition->GetDiagramLabel().c_str()
						<< "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
						<< std::endl;
				else if (aTransition->IsSelfTransition())
					stream << "\t"
						<< aState->GetName().c_str()
						<< "->"
						<< aState->GetName().c_str()
						<< " [label=\""
						<< aTransition->GetDiagramLabel().c_str()
						<< "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
						<< std::endl;
			}
			delete anElement2;
		}
	}
	delete anElement;
}

stream << "}" << std::endl;

return stream;
