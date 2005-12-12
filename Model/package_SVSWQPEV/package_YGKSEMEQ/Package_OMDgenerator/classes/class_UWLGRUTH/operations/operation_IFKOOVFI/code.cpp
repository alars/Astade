// vi: set tabstop=4:
wxFileName path = pe->GetFileName();
AdeDirectoryElement de(path);

for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
{
	AdeModelElement* pme = eit.CreateNewElement();
	if ((pme->GetType() & 0x0ff00000) == ITEM_IS_OPERATIONS)
	{
		wxFileName path = pme->GetFileName();
		AdeDirectoryElement ode(path);
		for (AdeElementIterator it = ode.begin(); it != ode.end(); ++it)
		{
			AdeModelElement* po = it.CreateNewElement();
			if ((po->GetType() & 0x0ff00000) == ITEM_IS_OPERATION)
			{
				tVisibility vis = PUBLIC;
				if ((po->GetType() & ITEM_IS_PROTECTED) != 0)
					vis = PROTECTED;
				if ((po->GetType() & ITEM_IS_PRIVATE) != 0)
					vis = PRIVATE;
				if (vis <= showattr)
				{
					switch (vis)
					{
						case PUBLIC:
							std::cout << "+ ";
							break;

						case PROTECTED:
							std::cout << "# ";
							break;

						case PRIVATE:
							std::cout << "- ";
							break;
					}
					std::cout << po->GetName()
						<< "()\\l";
				}
			}
			delete po;
		}
	}
	delete pme;
}
