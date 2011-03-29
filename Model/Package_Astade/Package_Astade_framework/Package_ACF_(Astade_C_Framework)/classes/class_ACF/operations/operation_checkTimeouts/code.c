//~~ void checkTimeouts() [ACF] ~~
unsigned int now = ACF_getTimeTick();
unsigned int diff = now - ACF_lastTime;
ACF_lastTime = now;

while (ACF_scheduledTimeouts && diff)
{
    if (diff <= ACF_my_Timeouts[0].Time)
    {
        ACF_my_Timeouts[0].Time -= diff;
        diff = 0;
    }
    else
    {
        diff -= ACF_my_Timeouts[0].Time;
        ACF_my_Timeouts[0].Time = 0;
    }
    
    while (ACF_scheduledTimeouts && ACF_my_Timeouts[0].Time == 0)
    {
        ACF_sendTimeoutMessage((ACF_MessageReceiver*)ACF_my_Timeouts[0].Destination);
        --ACF_scheduledTimeouts;
        memmove(&ACF_my_Timeouts[0], &ACF_my_Timeouts[1], sizeof(ACF_my_Timeouts[0]) * ACF_scheduledTimeouts);
    }
}
