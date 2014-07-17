//~~ void printName(AdeModelElement* element, bool full) [ACDescribable] ~~
wxString name(element->GetLabel());
name.Replace(wxS(" "),wxS("_"));

printf("%s",name.mb_str().data());
