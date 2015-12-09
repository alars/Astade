//~~ void Initialize() [test_capsule] ~~
tcp_Initialize(&me->my_tcp_receiver.tcp_base,0);
tcp_Initialize(&me->my_tcp_sender.tcp_base,0);

test_receiver_Initialize(&me->my_test_receiver.test_receiver_base,0);
test_sender_Initialize(&me->my_test_sender.test_sender_base,0);