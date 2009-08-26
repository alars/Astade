AdeElementIterator it;

for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PARAMETERS)
	{
		AdeParameters* aParameters = dynamic_cast<AdeParameters*>(aElement);
		if(aParameters)
		{
			std::map<int,AdeParameter*> parameterlist;

			AdeElementIterator it2;
			for (it2 = aParameters->begin(); it2 != aParameters->end(); ++it2)
			{
				AdeParameter* aParameter = dynamic_cast<AdeParameter*>(it2.CreateNewElement());
				if(aParameter)
				{
					parameterlist[aParameter->GetType()] = aParameter;
				}
			}

			std::map<int,AdeParameter*>::iterator it3;
			std::list<AdeParameter*> ret;

			for (it3 = parameterlist.begin(); it3 != parameterlist.end(); ++it3)
			{
				ret.push_back((*it3).second);
			}
			delete aParameters;
			return ret;
		}
	}
	delete aElement;
}

return std::list<AdeParameter*>();
