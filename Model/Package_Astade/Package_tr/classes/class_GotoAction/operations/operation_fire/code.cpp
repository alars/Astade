//~~ void fire() [GotoAction] ~~
if (myRunner)
{
    myRunner->doGoto(text);
    myRunner->notifyAction(std::string("<GOTO ") + text + ">");
}