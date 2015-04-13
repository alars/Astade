for (std::vector< boost::shared_ptr<Trigger> >::iterator it = myWatches.begin(); it != myWatches.end(); it++)
{
    if ((*it)->checkTrigger(data))
        RETURN(true);
}

Section* p = getParent();
if (p)
{
    RETURN(p->checkWatch(runner,data));
} else {
    RETURN(false);
}
