//~~ void fire() [FailAction] ~~
if (tr::Test::currentTest)
    tr::Test::currentTest->result = false;

myRunner->notifyAction("<FAIL>");