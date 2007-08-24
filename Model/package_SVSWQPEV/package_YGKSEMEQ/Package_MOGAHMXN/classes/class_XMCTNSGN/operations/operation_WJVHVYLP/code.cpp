wxMenu* aSubUp = new wxMenu(wxEmptyString);

/** TBD: this does not work correcly, yet!

std::map<wxString, wxString> ops = dynamic_cast<AdeClass*>(myModelElement)->GetOverloadableOperations();

std::map<wxString, wxString>::iterator it;

for(it=ops.begin(); it!=ops.end(); ++it)
{
	aSubUp->Append(-1, it->first, wxEmptyString, wxITEM_NORMAL);
}
*/

return aSubUp;
