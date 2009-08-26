std::list<AdeParameter*> parameterlist = Parameterlist();
wxString ret;

for (std::list<AdeParameter*>::iterator it = parameterlist.begin(); it != parameterlist.end(); ++it)
{
	if (it != parameterlist.begin())
		ret += ", ";
	ret += (*it)->GetLabel();
	delete (*it);
}

return ret;
