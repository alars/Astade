//~~ void run() [RunnerInterface] ~~
unsigned int currentTimeout;

while (1) 
{
    while (currentSection->checkTrigger(*this, inputBuffer, 0, currentTimeout));
    break;
};