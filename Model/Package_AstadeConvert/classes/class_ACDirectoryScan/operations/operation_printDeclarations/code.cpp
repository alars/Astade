//~~ void printDeclarations() [ACDirectoryScan] ~~
for (AdeElementIterator it = m_Dir.begin(); it != m_Dir.end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    ACDescribable* d = createDescribable(anElement);
    d->printDeclaration();
    delete anElement;
    delete d;
}
