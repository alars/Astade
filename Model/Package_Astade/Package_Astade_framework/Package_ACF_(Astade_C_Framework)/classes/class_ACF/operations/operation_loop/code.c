while (1)
	if (!ACF_handleMessage())
		ACF_wait(ACF_scheduledTimeouts ? ACF_my_Timeouts[0].Time : -1);
