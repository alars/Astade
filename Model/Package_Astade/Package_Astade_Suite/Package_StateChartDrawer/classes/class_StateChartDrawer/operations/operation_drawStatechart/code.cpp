//~~ std::ostream& drawStatechart(std::ostream& stream, AdeStatechart& theStatechart) [StateChartDrawer] ~~

stream << "digraph G {" << std::endl;

stream << "\tfontsize=10\n\tlabelloc = \"t\"\n\tlabeljust = \"l\"" << std::endl;
stream << "\tlabel = \"" << theStatechart.GetName().utf8_str() << "\\n" << theStatechart.GetDescription().utf8_str() << "\"" << std::endl;

stream << "\tNOSTATE [shape=circle label=\"\" width=0.2 style=filled fillcolor=black color=black];" << std::endl;

stream << "\tNOSTATE->"
    << theStatechart.GetInitialState().utf8_str()
    << " [label=\""
    << theStatechart.GetDiagramLabel().utf8_str()
    << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
    << std::endl;

bool haveTerminate = false;
bool haveAnystate = false;

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
    {
        AdeState* aState = dynamic_cast<AdeState*>(anElement);
        stream << "\t"
            << aState->GetName().utf8_str();

            if (!aState->isIf())
                stream << " [label=\"{"
                    << aState->GetDiagramLabel().utf8_str()
                    << "}\", shape=Mrecord, color=darkviolet, fontname=arial, fontsize=12];";
            else
                stream << " [label=\""
                    << aState->GetDiagramLabel().utf8_str()
                    << "\", shape=diamond, color=blue, fontname=arial, fontsize=10];";

            stream << std::endl;

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
                        << aState->GetName().utf8_str()
                        << "->"
                        << aTransition->GetDestination().utf8_str()
                        << " [label=\""
                        << aTransition->GetDiagramLabel().utf8_str()
                        << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
                        << std::endl;
                else if (aTransition->IsSelfTransition())
                    stream << "\t"
                        << aState->GetName().utf8_str()
                        << "->"
                        << aState->GetName().utf8_str()
                        << " [label=\""
                        << aTransition->GetDiagramLabel().utf8_str()
                        << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
                        << std::endl;
                else if (aTransition->IsTerminateTransition())
                {
                    haveTerminate = true;
                    stream << "\t"
                        << aState->GetName().utf8_str()
                        << "->"
                        << "TERMINATESTATE"
                        << " [label=\""
                        << aTransition->GetDiagramLabel().utf8_str()
                        << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
                        << std::endl;
                }
            }
            delete anElement2;
        }
    } else if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
    {
        haveAnystate = true;
        AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
        if (aTransition->IsNormalTransition() &&
            !aTransition->GetDestination().empty())
            stream << "\t"
                << "ANYSTATE"
                << "->"
                << aTransition->GetDestination().utf8_str()
                << " [label=\""
                << aTransition->GetDiagramLabel().utf8_str()
                << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
                << std::endl;
        else if (aTransition->IsSelfTransition())
            stream << "\t"
                << "ANYSTATE"
                << "->"
                << "ANYSTATE"
                << " [label=\""
                << aTransition->GetDiagramLabel().utf8_str()
                << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
                << std::endl;
        else if (aTransition->IsTerminateTransition())
        {
            haveTerminate = true;
            stream << "\t"
                << "ANYSTATE"
                << "->"
                << "TERMINATESTATE"
                << " [label=\""
                << aTransition->GetDiagramLabel().utf8_str()
                << "\", color=black, fontname=arial, fontsize=10,  arrowhead=vee];"
                << std::endl;
        }
    }
    
    delete anElement;
}

if (haveTerminate)
    stream << "\tTERMINATESTATE [shape=doublecircle label=\"\" width=0.2 style=filled fillcolor=black color=black];" << std::endl;

if (haveAnystate)
    stream << "\tANYSTATE"
           << " [label=\"{"
           << theStatechart.GetAnystateLabel().utf8_str()
           << "}\", shape=Mrecord, color=darkviolet, fontname=arial, fontsize=12];"
           << std::endl;


stream << "}" << std::endl;

return stream;
