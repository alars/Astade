AdeElementIterator it;

for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x8F00000) == ITEM_IS_PARAMETERS)
	{
		AdeParameters* aParameters = static_cast<AdeParameters*>(aElement);

		std::map<int,wxString> parameterlist;

		AdeElementIterator it2;
		for (it2=aParameters->begin();it2!=aParameters->end();++it2)
		{
			AdeParameter* aParameter = static_cast<AdeParameter*>(it2.CreateNewElement());
			parameterlist[aParameter->GetType()] = aParameter->GetLabel();
			delete aParameter;
		}

		std::map<int,wxString>::iterator it3;
		wxString ret;

		for (it3=parameterlist.begin(); it3!=parameterlist.end(); ++it3)
		{
			if (it3!=parameterlist.begin())
				ret = ret + ", ";
			ret = ret + (*it3).second;
		}

		delete aElement;
		return ret;
	}

	delete aElement;
}

return "";