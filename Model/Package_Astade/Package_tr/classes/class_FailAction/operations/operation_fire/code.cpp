//~~ void fire() [FailAction] ~~
if (tr::Test::currentTest)
    tr::Test::currentTest->result = false;

if (myRunner)
    myRunner->notifyAction("<FAIL>");