//~~ wxArrayString GetMultiplicityImplementations() [ResourceEdit] ~~
wxArrayString ret;
ret.Add(wxS("1"));
ret.Add(wxS("0..1"));
ret.Add(wxS("1..*"));
ret.Add(wxS("*"));
return ret;
