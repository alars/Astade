//~~ wxArrayString GetRelationImplementations() [ResourceEdit] ~~

wxArrayString ret;
const AdeRelation* relation = dynamic_cast<const AdeRelation*>(AdeModelElement::CreateNewElement(wxFileName(wxString(wxTheApp->argv[1]))));
if (!relation)
	return ret;
const AdeClass* daddy   = dynamic_cast<const AdeClass*>(relation->GetParent());
const AdeClass* partner = dynamic_cast<const AdeClass*>(relation->GetPartner());
if (!partner)
	return ret;

wxArrayString partner_space(partner->getNamespace());
if (daddy)
{
	wxArrayString daddy_space  (daddy  ->getNamespace());
	unsigned int ix;
	for (ix = 0; ix < daddy_space.GetCount() && ix < partner_space.GetCount(); ++ix)
		if (daddy_space[ix] != partner_space[ix])
			break;
	partner_space.RemoveAt(0, ix);
}

wxString full_name = getNamespace(partner_space) + partner->GetLabel();
ret.Add(full_name + wxS("*"));
ret.Add(full_name);
ret.Add(wxS("std::set<")    + full_name + wxS("*>"));
ret.Add(wxS("std::list<")   + full_name + wxS("*>"));
ret.Add(wxS("std::vector<") + full_name + wxS("*>"));
ret.Add(wxS("std::deque<")  + full_name + wxS("*>"));
ret.Add(wxS("std::map<")    + full_name + wxS("*, ?>"));
return ret;
