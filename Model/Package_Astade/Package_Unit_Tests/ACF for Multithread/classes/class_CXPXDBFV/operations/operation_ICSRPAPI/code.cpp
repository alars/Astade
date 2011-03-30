//~~ void main() [TopCapsule] ~~
pthread_t Thread1;
pthread_create(&Thread1,0,&ACF::staticExec,&ThreadContext1);

pthread_t Thread2;
pthread_create(&Thread2,0,&ACF::staticExec,&ThreadContext2);

sleep(1);

machine1.Initialize(0);
machine2.Initialize(0);

while (1) sleep(20);