//~~ void scheduleTimeout(ACF_MessageReceiver* Destination, unsigned int Time) [ACF] ~~

cancelTimeout(Destination);

while (sem_wait(&myQueueSemaphore))
    continue;

while (scheduledTimeouts == my_Timeouts.size())
    my_Timeouts.push_back(ACF_Timeout());

Time += getTimeTick() - lastTime;	// adjust for time since last checkTimeouts()
unsigned int timeSum = 0;
unsigned int index = 0;

while (index < scheduledTimeouts && my_Timeouts[index].Time + timeSum <= Time)
{
    timeSum += my_Timeouts[index].Time;
    ++index;
}

if (index < scheduledTimeouts)
{
    my_Timeouts[index].Time -= Time - timeSum;
    memmove(&my_Timeouts[index + 1], &my_Timeouts[index], sizeof(my_Timeouts[0]) * (scheduledTimeouts - index));
}

my_Timeouts[index].Destination = Destination;
my_Timeouts[index].Time = Time - timeSum;
++scheduledTimeouts;

sem_post(&myQueueSemaphore);
interruptSleep();
