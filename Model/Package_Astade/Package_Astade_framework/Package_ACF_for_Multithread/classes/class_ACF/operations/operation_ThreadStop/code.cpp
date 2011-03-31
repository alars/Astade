//~~ void ThreadStop() [ACF] ~~
if (isRunning)
{
    keepRunning = false;
    interruptSleep();
    while (isRunning)
        sleep(0);
}
