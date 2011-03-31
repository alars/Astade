//~~ void exec() [ACF] ~~
isRunning = true;

while (keepRunning)
{   
    checkTimeouts();
    handleMessage();
    if (nextRead == nextWrite) // queue is empty, so we goto sleep
        interuptableSleep();
}

isRunning = false;