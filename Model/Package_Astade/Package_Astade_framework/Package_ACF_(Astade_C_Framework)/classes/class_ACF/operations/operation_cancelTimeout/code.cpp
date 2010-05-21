//~~ void cancelTimeout(ACF_MessageReceiver* Destination) [ACF] ~~
int i;
int last = ACF_scheduledTimeouts-1;

if (ACF_scheduledTimeouts == 0)
    return;

if (ACF_my_Timeouts[last].Destination == Destination) 
{
    --ACF_scheduledTimeouts;
   return;
}

for (i = 0; i < last; i++)
{
    if (ACF_my_Timeouts[i].Destination == Destination)
    {
        ACF_my_Timeouts[i+1].Time += ACF_my_Timeouts[i].Time;
        memmove(&ACF_my_Timeouts[i],&ACF_my_Timeouts[i+1],sizeof(ACF_my_Timeouts[i])*(last));
        --ACF_scheduledTimeouts;
        break;
    }
}
