//~~ std::map<wxString, wxString> GetVirtualOperations() [AdeStatechart] ~~

std::map<wxString, wxString> retVal;

wxString event = GetEventType() + wxS("&");
wxString coder = GetCoderSuffix();
if (coder == wxS("C"))
	event = wxS("const ") + event;
else if (coder.StartsWith(wxS("ACF")))
	event = wxS("ACF_Message*");
else if (coder == wxS("VSM"))
	event = wxS("CMessage&");
else if (coder == wxS("Wx"))
	event = wxS("wxEvent&");

std::set<wxString> aSet = GetActions();
for (std::set<wxString>::iterator it = aSet.begin(); it != aSet.end(); ++it)
{
	wxString op = *it;
	op += wxS("(") + event + wxS(")");
	retVal[op] = wxS("void");
}
aSet = GetGuards();
for (std::set<wxString>::iterator it = aSet.begin(); it != aSet.end(); ++it)
{
	wxString op = *it;
	op += wxS("(") + event + wxS(")");
	retVal[op] = wxS("bool");
}

return retVal;
