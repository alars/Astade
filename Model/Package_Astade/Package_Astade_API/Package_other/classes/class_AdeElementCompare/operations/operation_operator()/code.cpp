//~~ bool operator()(const AdeModelElement* const& lhs, const AdeModelElement* const& rhs) [AdeElementCompare] ~~
wxString l(lhs->GetLabel());
wxString r(rhs->GetLabel());
int rc = l.CmpNoCase(r);
if (rc == 0)
	rc = l.Cmp(r);
return rc < 0;
