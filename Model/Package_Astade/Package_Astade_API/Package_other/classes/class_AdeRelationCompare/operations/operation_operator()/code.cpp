//~~ bool operator()(const AdeRelation* const& lhs, const AdeRelation* const& rhs) [AdeRelationCompare] ~~
wxString l(lhs->GetSortName());
wxString r(rhs->GetSortName());
int rc = l.CmpNoCase(r);
if (rc == 0)
	rc = l.Cmp(r);
return rc < 0;
