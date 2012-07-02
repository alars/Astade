//~~ void ListNodes(int depth, const wxString& parent, const AdeModelElement* pe) [OMDgenerator] ~~

wxFileName path = pe->GetFileName();
AdeDirectoryElement de(path);

if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS)
{
	const AdeClass* pc = dynamic_cast<const AdeClass*>(pe);
	assert(pc);
	tList attributes, operations;
	wxString prename(parent);
	if (!parent.IsEmpty())
		prename = prename + wxS(":") + pe->GetName();
	else
		prename = pe->GetName();

	if (showall || pc->IsInActiveComponent())
	{
		wxString nodename(path.GetDirs()[path.GetDirCount()-1]);
		nodelist.insert(nodename);
		if (!pc->IsLibClass())
		{
			if (showattr != NONE || showoper != NONE)
				AnalyseClass(pe, attributes, operations);
			std::cout << std::endl;
			IndentOutput(depth);
			std::cout << CleanName(path.GetDirs()[path.GetDirCount()-1]).utf8_str()
				<< " [shape=record, label=\"{"
				<< prename.utf8_str()
				<< '|';
			for (int i = 0; i < showattr && static_cast<unsigned int>(i) < attributes.size(); ++i)
				for (std::set<wxString, AdeStringCompare>::iterator it = attributes[i].begin();
					it != attributes[i].end(); ++it)
				{
					switch (i)
					{
					case 0:
						std::cout << "+ ";
						break;

					case 1:
						std::cout << "# ";
						break;

					case 2:
						std::cout << "- ";
						break;
					}
					std::cout << it->utf8_str() << "\\l";
				}
			std::cout << '|';
			for (int i = 0; i < showoper && static_cast<unsigned int>(i) < operations.size(); ++i)
				for (std::set<wxString, AdeStringCompare>::iterator it = operations[i].begin();
					it != operations[i].end(); ++it)
				{
					switch (i)
					{
					case 0:
						std::cout << "+ ";
						break;

					case 1:
						std::cout << "# ";
						break;

					case 2:
						std::cout << "- ";
						break;
					}
					wxString tmp(it->Mid(1));
					tmp.Replace(wxS("<"), wxS("\\<"));
					tmp.Replace(wxS(">"), wxS("\\>"));
					tmp.Replace(wxS("|"), wxS("\\|"));
					std::cout << tmp.utf8_str() << "()\\l";
				}
			std::cout << "}\", style=filled, fillcolor=grey95, color=black];"
				<< std::endl;

            if (showports)
                CodePorts(depth, pc, nodename);

			for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
			{
				AdeModelElement* pme = eit.CreateNewElement();
				ListNodes(depth, prename, pme);
				delete pme;
			}
		}
		else
		{
			// lib class, no details:
			std::cout << CleanName(path.GetDirs()[path.GetDirCount()-1]).utf8_str()
				<< " [label=\""
				<< prename.utf8_str()
				<< "\", style=filled, fillcolor=grey95, color=black];"
				<< std::endl;
		}
	}
}
else if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
{
	const AdeStatechart* pc = dynamic_cast<const AdeStatechart*>(pe);
	assert(pc);
	wxString prename(parent);
	if (!parent.IsEmpty())
		prename = prename + wxS(":") + pe->GetName();
	else
		prename = pe->GetName();

	if (showall || pc->IsInActiveComponent())
	{
		wxString nodename(path.GetDirs()[path.GetDirCount()-1]);
		nodelist.insert(nodename);
		std::cout << std::endl;
		IndentOutput(depth);
		std::cout << path.GetDirs()[path.GetDirCount()-1].utf8_str()
			<< " [shape=record, label=\"{"
			<<  "«statechart»\\n"
			<< prename.utf8_str()
			<< "}\", style=filled, fillcolor=grey95, color=black];"
			<< std::endl;

		for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
		{
			AdeModelElement* pme = eit.CreateNewElement();
			ListNodes(depth, prename, pme);
			delete pme;
		}
	}
}
else if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASSES)
{
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth, parent, pme);
		delete pme;
	}
}
else if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE)
{
	wxString filename;
	wxDir dir(path.GetPath());

	IndentOutput(depth);
	std::cout << "subgraph cluster"
		<< CleanName(path.GetDirs()[path.GetDirCount()-1]).utf8_str()
		<< " {"
		<< std::endl;
	IndentOutput(depth);
	std::cout << "\tlabel=\"Package: "
		<< pe->GetName().utf8_str()
		<< "\"; labeljust=left; fontname=Helvetica; fontsize=10; color=red;"
		<< std::endl;
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth + 1, parent, pme);
		delete pme;
	}
	IndentOutput(depth);
	std::cout << '}'
		<< std::endl;
}
