//~~ void reportBegin() [Test] ~~

std::cout << "Test " << mName << " begin" << std::endl;
currentTest = this;

if (myRunner->getReportFile())
    (*myRunner->getReportFile())
        << "\t<SetResult caseID=\""
        << mTestNumber
        << "\">"
        << std::endl
        << "\t\t<Annotation>"
        << std::endl;