//~~ void AnalyseClass(const AdeModelElement* pe, tList& attributes, tList& operations) [OMDgenerator] ~~

wxFileName path = pe->GetFileName();
AdeDirectoryElement de(path);

for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
{
	AdeModelElement* pme = eit.CreateNewElement();
	if ((pme->GetType() & ITEM_TYPE_MASK) == ITEM_IS_ATTRIBUTES)
	{
		wxFileName path = pme->GetFileName();
		AdeDirectoryElement ade(path);
		for (AdeElementIterator it = ade.begin(); it != ade.end(); ++it)
		{
			AdeModelElement* pa = it.CreateNewElement();
			if ((pa->GetType() & ITEM_TYPE_MASK) == ITEM_IS_ATTRIBUTE)
			{
				int vis = 0;
				if ((pa->GetType() & ITEM_IS_PROTECTED) != 0)
					vis = 1;
				if ((pa->GetType() & ITEM_IS_PRIVATE) != 0)
					vis = 2;
				if (vis < showattr)
				{
					while (attributes.size() <= static_cast<unsigned int>(vis))
						attributes.push_back(std::set<wxString, AdeStringCompare>());
					attributes[vis].insert(pa->GetName());
				}
			}
			delete pa;
		}
	}
	else if ((pme->GetType() & ITEM_TYPE_MASK) == ITEM_IS_OPERATIONS)
	{
		wxFileName path = pme->GetFileName();
		AdeDirectoryElement ode(path);
		for (AdeElementIterator it = ode.begin(); it != ode.end(); ++it)
		{
			AdeModelElement* po = it.CreateNewElement();
			if ((po->GetType() & ITEM_TYPE_MASK) == ITEM_IS_OPERATION)
			{
				int vis = 0;
				if ((po->GetType() & ITEM_IS_PROTECTED) != 0)
					vis = 1;
				if ((po->GetType() & ITEM_IS_PRIVATE) != 0)
					vis = 2;
				if (vis < showoper)
				{
					wxString kludge(wxS("0"));
					if ((po->GetType() & ITEM_IS_DEST) != 0)
						kludge = wxS("1");
					if ((po->GetType() & ITEM_IS_NORMALOP) != 0)
						kludge = wxS("2");
					while (operations.size() <= static_cast<unsigned int>(vis))
						operations.push_back(std::set<wxString, AdeStringCompare>());
					operations[vis].insert(kludge + po->GetName());
				}
			}
			delete po;
		}
	}
	delete pme;
}
