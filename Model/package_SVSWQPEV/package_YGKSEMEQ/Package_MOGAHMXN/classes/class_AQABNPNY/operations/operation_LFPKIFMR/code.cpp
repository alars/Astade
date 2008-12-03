wxArrayString names;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myModelElement->GetFileName().GetFullPath());

wxString TransitionType = theConfig.Read("Astade/TransitionType");

if (TransitionType=="Self")
	names.Add("selftransition");
else if (TransitionType=="Internal")
	names.Add("internaltransition");
else
	names.Add("transition");

if(myModelElement->IsUndocumented())
	names.Add("isundocumented");
else if(myModelElement->ContainsUndocumented())
	names.Add("containundocumented");
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
