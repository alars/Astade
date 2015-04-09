//~~ void fire() [Trigger] ~~
for (std::vector< boost::shared_ptr<Action> >::iterator it = myActions.begin(); it != myActions.end(); it++)
{
    (*it)->fire();
};
