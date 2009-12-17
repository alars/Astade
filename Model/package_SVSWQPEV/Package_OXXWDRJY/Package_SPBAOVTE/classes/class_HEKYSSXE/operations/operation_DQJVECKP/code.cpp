ACF_cancelTimeout(Destination);

if (ACF_scheduledTimeouts == 0)
{
    ACF_my_Timeouts[0].Destination = Destination;
    ACF_my_Timeouts[0].Time = Time;
    ACF_scheduledTimeouts = 1;
    voidRETURN;
}