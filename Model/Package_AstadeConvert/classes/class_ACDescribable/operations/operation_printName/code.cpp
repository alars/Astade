//~~ void printName(unsigned int indent, const char* keyword, AdeModelElement* element, bool full) [ACDescribable] ~~
wxString name(element->GetName());

if (full)
{
    AdeModelElement* parent = element->GetParent();
    int count = 0;
    while ((dynamic_cast<AdeModel*>(parent) == 0) && (count++ < 10))//not the root element
    {
        if (dynamic_cast<AdeComponents*>(parent) != 0)
        {
            name = parent->GetName() + wxS(".") + name;
        }
        if (dynamic_cast<AdePackage*>(parent) != 0)
        {
            AdePackage* p = dynamic_cast<AdePackage*>(parent);
            if (p->isNamespace())
                name = parent->GetName() + wxS(".") + name;
        }
        AdeModelElement* old = parent;
        parent = old->GetParent();
        delete old;
    }
    delete parent;
    printf("\n");
}

name.Replace(wxS(" "),wxS("_"));

pIndent(indent);
printf("%s [%s]",keyword, name.mb_str().data());


if (full)
{
    printf(" {\n");
}
else
{
    printf(";\n");
}
