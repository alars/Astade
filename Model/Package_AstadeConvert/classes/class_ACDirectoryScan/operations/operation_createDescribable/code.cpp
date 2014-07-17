//~~ ACDescribable* createDescribable(AdeModelElement* element) [ACDirectoryScan] ~~

if (dynamic_cast<AdeComponents*>(element))
    return new ACProject(dynamic_cast<AdeComponents*>(element));

if (dynamic_cast<AdePackage*>(element))
    return new ACPackage(dynamic_cast<AdePackage*>(element));

return new ACUnknown(element);