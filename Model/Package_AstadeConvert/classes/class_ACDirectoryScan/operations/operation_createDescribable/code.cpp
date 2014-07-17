//~~ ACDescribable* createDescribable(AdeModelElement* element) [ACDirectoryScan] ~~

if (dynamic_cast<AdeComponents*>(element))
    return new ACProject(dynamic_cast<AdeComponents*>(element));

return new ACUnknown(element);