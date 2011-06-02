//~~ std::list<AdeParameter*> Parameterlist() [AdeOperationBase] ~~

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PARAMETERS)
	{
		AdeParameters* aParameters = dynamic_cast<AdeParameters*>(anElement);
		if (aParameters)
		{
			std::map<int,AdeParameter*> parameterlist;
			for (AdeElementIterator it2 = aParameters->begin(); it2 != aParameters->end(); ++it2)
			{
				AdeParameter* aParameter = dynamic_cast<AdeParameter*>(it2.CreateNewElement());
				if (aParameter)
				{
					parameterlist[aParameter->GetType()] = aParameter;
				}
			}

			std::list<AdeParameter*> ret;
			for (std::map<int,AdeParameter*>::iterator it3 = parameterlist.begin(); it3 != parameterlist.end(); ++it3)
			{
				ret.push_back((*it3).second);
			}
			delete aParameters;
			return ret;
		}
	}
	delete anElement;
}

return std::list<AdeParameter*>();
