//~~ int init_module() [trcDriver] ~~
trcDriver_mytrcStack[0].runningID = 0;
trcDriver_mytrcStack[0].runningName = "*";
trcDriver_mytrcStack[0].runningLevel = 0;

trcDriver_sm_procDir = proc_mkdir("driver/trace2uml",NULL);
kaProcEntry_Constructor(&trcDriver_sm_trace,"trace", kaProcEntry_READ_ONLY, trcDriver_sm_procDir);
kaProcEntry_registerReadFunction(&trcDriver_sm_trace,&trcDriver_readTrace);

return(0);
