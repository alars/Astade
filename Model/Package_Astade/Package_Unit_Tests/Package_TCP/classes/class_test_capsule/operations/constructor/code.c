//~~ test_capsule(ACF* anACF) [test_capsule] ~~
tcp_impl_Constructor(&me->my_tcp_receiver, anACF);
tcp_impl_Constructor(&me->my_tcp_sender, anACF);

test_receiver_impl_Constructor(&me->my_test_receiver, anACF);
test_sender_impl_Constructor(&me->my_test_sender, anACF);
