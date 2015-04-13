//~~ void nextSection() [Section] ~~
currentLine = 0;
currentSubsection++;
if (!hasLines())
{
    Section* p = getParent();
    if (p)
        p->nextSection();
}