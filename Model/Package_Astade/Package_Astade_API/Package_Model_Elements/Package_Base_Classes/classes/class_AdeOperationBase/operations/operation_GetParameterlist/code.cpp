//~~ wxString GetParameterlist() [AdeOperationBase] ~~
std::list<AdeParameter*> parameterlist = Parameterlist();
wxString ret;

for (std::list<AdeParameter*>::iterator it = parameterlist.begin(); it != parameterlist.end(); ++it)
{
	if (it != parameterlist.begin())
		ret += wxS(", ");
	ret += (*it)->GetLabel();
	delete *it;
}

return ret;
