//~~ std::map<wxString, wxString> GetVirtualOperations() [AdeStatechart] ~~

std::map<wxString, wxString> retVal;

std::set<wxString> aSet = GetActions();
std::set<wxString> anotherSet = GetGuards();
aSet.insert(anotherSet.begin(), anotherSet.end());

wxString event = GetEventType() + wxS("&");
wxString coder = GetCoderSuffix();
if (coder == wxS("ACF++"))
	event = wxS("ACF_Message*");
else if (coder == "VSM")
	event = wxS("CMessage&");
else if (coder == "Wx")
	event = wxS("wxEvent&");
for (std::set<wxString>::iterator it = aSet.begin(); it != aSet.end(); ++it)
{
	wxString op = *it;
	op += wxS("(") + event + wxS(")");
	retVal[op] = wxEmptyString;
}

return retVal;
