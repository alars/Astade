//~~ void run() [RunnerInterface] ~~
unsigned int currentTimeout;

while (currentSection->hasLines()) 
{
    currentSection->checkTrigger(*this, inputBuffer, 0, currentTimeout);
    if (!currentSection->hasLines())
        currentSection->nextSection();
    else
        inputBuffer += readChar(0);
};