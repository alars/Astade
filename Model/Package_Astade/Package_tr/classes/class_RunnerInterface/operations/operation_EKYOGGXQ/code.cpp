//~~ void doGoto(const std::string& target) [RunnerInterface] ~~
Section* aSection = currentSection->find(target,true);
if (aSection)
{
    Section* pSection = aSection->getParent();
    if (pSection)
        pSection->doGoto(aSection);
}
else 
    std::cout << "RUNTIME ERROR: no section " << target << std::endl;