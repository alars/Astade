//~~ void reportEnd() [Test] ~~

if (result)
{
    std::cout << "Test " << mName << " successful!" << std::endl;
    if (myRunner->getReportFile())
        (*myRunner->getReportFile())
            << "\t\t</Annotation>"
            << std::endl
            << "\t\t<Verdict>Passed</Verdict>"
            << std::endl
            << "\t</SetResult>"
            << std::endl;
} else {
    std::cout << "Test " << mName << " failed!" << std::endl;
    if (myRunner->getReportFile())
        (*myRunner->getReportFile())
            << "\t\t</Annotation>"
            << std::endl
            << "\t\t<Verdict>Failed</Verdict>"
            << std::endl
            << "\t</SetResult>"
            << std::endl;
}

currentTest = 0;
