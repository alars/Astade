//~~ ACDescribable* createDescribable(AdeModelElement* element) [ACDirectoryScan] ~~

if (dynamic_cast<AdeComponents*>(element))
    return new ACProject(dynamic_cast<AdeComponents*>(element));

if (dynamic_cast<AdePackage*>(element))
    return new ACPackage(dynamic_cast<AdePackage*>(element));

if (dynamic_cast<AdeClasses*>(element))
    return new ACClasses(dynamic_cast<AdeClasses*>(element));

if (dynamic_cast<AdeClass*>(element))
    return new ACClass(dynamic_cast<AdeClass*>(element));

return new ACUnknown(element);