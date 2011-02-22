//~~ void loop() [ACF] ~~

while (1)
	if (!ACF_handleMessage())
		ACF_wait(ACF_getShortestTimer());
