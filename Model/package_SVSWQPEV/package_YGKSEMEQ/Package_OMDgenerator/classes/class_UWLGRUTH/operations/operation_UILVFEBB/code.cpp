// vi: set tabstop=4:
wxFileName path = pe->GetFileName();
AdeDirectoryElement de(path);

for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
{
	AdeModelElement* pme = eit.CreateNewElement();
	if ((pme->GetType() & 0x0ff00000) == ITEM_IS_ATTRIBUTES)
	{
		wxFileName path = pme->GetFileName();
		AdeDirectoryElement ade(path);
		for (AdeElementIterator it = ade.begin(); it != ade.end(); ++it)
		{
			AdeModelElement* pa = it.CreateNewElement();
			if ((pa->GetType() & 0x0ff00000) == ITEM_IS_ATTRIBUTE)
			{
				tVisibility vis = PUBLIC;
				if ((pa->GetType() & ITEM_IS_PROTECTED) != 0)
					vis = PROTECTED;
				if ((pa->GetType() & ITEM_IS_PRIVATE) != 0)
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
					std::cout << pa->GetName()
						<< "\\l";
				}
			}
			delete pa;
		}
	}
	delete pme;
}
