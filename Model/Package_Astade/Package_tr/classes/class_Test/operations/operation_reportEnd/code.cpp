//~~ void reportEnd() [Test] ~~

if (result)
    std::cout << "Test " << mName << " successful!" << std::endl;
else
    std::cout << "Test " << mName << " failed!" << std::endl;
    
currentTest = 0;
