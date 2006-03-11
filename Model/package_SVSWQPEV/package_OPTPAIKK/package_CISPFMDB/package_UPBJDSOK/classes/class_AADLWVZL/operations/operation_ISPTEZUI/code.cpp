/* vi: set tabstop=4: */

AdeElementIterator it;

for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PARAMETERS)
	{
		AdeParameters* aParameters = dynamic_cast<AdeParameters*>(aElement);
		assert(aParameters);

		std::map<int,wxString> parameterlist;

		AdeElementIterator it2;
		for (it2 = aParameters->begin(); it2 != aParameters->end(); ++it2)
		{
			AdeParameter* aParameter = dynamic_cast<AdeParameter*>(it2.CreateNewElement());
			assert(aParameter);
			parameterlist[aParameter->GetType()] = aParameter->GetLabel();
			delete aParameter;
		}

		std::map<int,wxString>::iterator it3;
		wxString ret;

		for (it3 = parameterlist.begin(); it3 != parameterlist.end(); ++it3)
		{
			if (it3 != parameterlist.begin())
				ret = ret + ", ";
			ret = ret + (*it3).second;
		}
		delete aParameters;
		return ret;
	}
	delete aElement;
}

return wxEmptyString;
