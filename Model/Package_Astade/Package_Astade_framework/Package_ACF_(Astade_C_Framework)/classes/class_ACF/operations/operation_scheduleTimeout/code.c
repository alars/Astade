//~~ void scheduleTimeout(ACF_MessageReceiver* Destination, unsigned int Time) [ACF] ~~

ACF_cancelTimeout(Destination);
Time += ACF_getTimeTick() - ACF_lastTime;	// adjust for time since last checkTimeouts()
unsigned int timeSum = 0;
unsigned int index = 0;

while (index < ACF_scheduledTimeouts && ACF_my_Timeouts[index].Time + timeSum <= Time)
{
    timeSum += ACF_my_Timeouts[index].Time;
    ++index;
}

if (index < ACF_scheduledTimeouts)
{
    ACF_my_Timeouts[index].Time -= Time - timeSum;
    memmove(&ACF_my_Timeouts[index + 1], &ACF_my_Timeouts[index], sizeof(ACF_my_Timeouts[0]) * (ACF_scheduledTimeouts - index));
}

ACF_my_Timeouts[index].Destination = Destination;
ACF_my_Timeouts[index].Time = Time - timeSum;
++ACF_scheduledTimeouts;
