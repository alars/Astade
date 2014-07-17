//~~ void printForwardDeclarations(unsigned int indent) [ACDirectoryScan] ~~
for (AdeElementIterator it = m_Dir.begin(); it != m_Dir.end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    ACDescribable* d = createDescribable(anElement);
    d->printForwardDeclaration(indent+1);
    delete anElement;
    delete d;
}
