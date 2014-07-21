//~~ ACDescribable* createDescribable(AdeModelElement* element) [ACDirectoryScan] ~~

if (dynamic_cast<AdeComponents*>(element))
    return new ACProject(dynamic_cast<AdeComponents*>(element));

if (dynamic_cast<AdePackage*>(element))
    return new ACPackage(dynamic_cast<AdePackage*>(element));

if (dynamic_cast<AdeClasses*>(element))
    return new ACClasses(dynamic_cast<AdeClasses*>(element));

if (dynamic_cast<AdeStatechart*>(element))
    return new ACStatemachine(dynamic_cast<AdeStatechart*>(element));

if (dynamic_cast<AdeClass*>(element))
    return new ACClass(dynamic_cast<AdeClass*>(element));

if (dynamic_cast<AdeComponent*>(element))
    return new ACComponent(dynamic_cast<AdeComponent*>(element));

if (dynamic_cast<AdeConfiguration*>(element))
    return new ACConfiguration(dynamic_cast<AdeConfiguration*>(element));

if (dynamic_cast<AdeAttributes*>(element))
    return new ACAttributes(dynamic_cast<AdeAttributes*>(element));

if (dynamic_cast<AdeAttribute*>(element))
    return new ACAttribute(dynamic_cast<AdeAttribute*>(element));

if (dynamic_cast<AdeSourceFile*>(element))
    return new ACSourceFile(dynamic_cast<AdeSourceFile*>(element));

if (dynamic_cast<AdeOperations*>(element))
    return new ACOperations(dynamic_cast<AdeOperations*>(element));

if (dynamic_cast<AdeOperation*>(element))
    return new ACOperation(dynamic_cast<AdeOperation*>(element));

return new ACUnknown(element);