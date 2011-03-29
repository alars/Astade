//~~ void exec() [ACF] ~~
isRunning = true;

while (keepRunning)
{   
    checkTimeouts();
    handleMessage();
    interuptableSleep();
}

isRunning = false;