//~~ void loop() [ACF] ~~

while (1)
{
	ACF_checkTimeouts();
	if (!ACF_handleMessage())
		ACF_wait(ACF_getShortestTimer());
}
