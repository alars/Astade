//~~ void fire() [ReportAction] ~~
std::cout << text;

if (myRunner->getReportFile())
    (*myRunner->getReportFile())
        << text;