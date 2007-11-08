/* vi: set tabstop=4: */

wxFileName path = pe->GetFileName();
AdeDirectoryElement de(path);

if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS)
{
	const AdeClass* pc = dynamic_cast<const AdeClass*>(pe);
	assert(pc);
	tList attributes, operations;
	wxString prename(parent);
	if (!parent.IsEmpty())
		prename = prename + ":" + pe->GetName();
	else
		prename = pe->GetName();

	if (showall || pc->GetIsInActiveComponent())
	{
		wxString nodename(path.GetDirs()[path.GetDirCount()-1]);
		nodelist.insert(nodename);
		if (!pc->GetIsLibClass())
		{
			if (showattr != NONE || showoper != NONE)
				AnalyseClass(pe, attributes, operations);
			std::cout << std::endl;
			IndentOutput(depth);
			std::cout << CleanName(path.GetDirs()[path.GetDirCount()-1])
				<< " [shape=record, label=\"{"
				<< prename
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
					std::cout << *it << "\\l";
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
					wxString tmp = it->Mid(1);
					tmp.Replace(">","\\>");
					std::cout << tmp << "()\\l";
				}
			std::cout << "}\", style=filled, fillcolor=grey95, color=black];"
				<< std::endl;

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
			std::cout << CleanName(path.GetDirs()[path.GetDirCount()-1])
				<< " [label=\""
				<< prename
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
		prename = prename + ":" + pe->GetName();
	else
		prename = pe->GetName();

	if (showall || pc->GetIsInActiveComponent())
	{
		wxString nodename(path.GetDirs()[path.GetDirCount()-1]);
		nodelist.insert(nodename);
		std::cout << std::endl;
		IndentOutput(depth);
		std::cout << path.GetDirs()[path.GetDirCount()-1]
			<< " [shape=record, label=\"{"
			<<  "\xab" "statechart" "\xbb\\n"
			<< prename
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
		<< CleanName(path.GetDirs()[path.GetDirCount()-1])
		<< " {"
		<< std::endl;
	IndentOutput(depth);
	std::cout << "\tlabel=\"Package: "
		<< pe->GetName()
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
