std::list<AdeParameter*> parameterlist = Parameterlist();
wxString ret;

for (std::list<AdeParameter*>::iterator it = parameterlist.begin(); it != parameterlist.end(); ++it)
{
	if (it != parameterlist.begin())
		ret += ", ";
	ret += (*it)->GetCodingType();
	delete (*it);
}

ret = GetName() + "(" + ret + ")";
return ret;
