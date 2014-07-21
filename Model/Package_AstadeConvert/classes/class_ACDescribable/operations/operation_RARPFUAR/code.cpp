//~~ wxString names(AdeModelElement* element, wxString separator) [ACDescribable] ~~
wxString name(element->GetName());

AdeModelElement* parent = element->GetParent();
int count = 0;
while ((dynamic_cast<AdeModel*>(parent) == 0) && (count++ < 10))//not the root element
{
    if (dynamic_cast<AdeComponents*>(parent) != 0)
    {
        name = parent->GetName() + separator + name;
    }
    if (dynamic_cast<AdeComponent*>(parent) != 0)
    {
        name = parent->GetName() + separator + name;
    }
    if (dynamic_cast<AdePackage*>(parent) != 0)
    {
        AdePackage* p = dynamic_cast<AdePackage*>(parent);
        if (p->isNamespace())
            name = parent->GetName() + separator + name;
    }
    AdeModelElement* old = parent;
    parent = old->GetParent();
    delete old;
}
delete parent;

name.Replace(wxS(" "),wxS("_"));

return name;