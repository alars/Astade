//~~ void run() [RunnerInterface] ~~
while (currentSection->hasLines()) 
{
        int stillToWait = 1000*3600*24;
        unsigned int timeout = currentSection->getTimeout();
        if (timeout > 0)
        {
            unsigned int tick = getTimeTick();
            unsigned int alreadyWait = tick-lastTriggerTime;
            stillToWait = timeout - alreadyWait;
        }
        
        if (stillToWait>0)
        {
            while(currentSection->checkTrigger(inputBuffer))
                lastTriggerTime=getTimeTick();
            ;
            
            if (!currentSection->hasLines())
                currentSection->nextSection();
            else
            {
  
                    inputBuffer += readChar(stillToWait);
            }

            while(currentSection->checkTrigger(inputBuffer))
                lastTriggerTime=getTimeTick();
            ;

        } else {
            currentSection->checkTimeout(inputBuffer,true);
            sleep(1);
        }
};