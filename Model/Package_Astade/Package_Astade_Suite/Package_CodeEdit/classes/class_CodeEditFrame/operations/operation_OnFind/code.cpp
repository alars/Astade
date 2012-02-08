int flags = 0;

if (event.GetFlags() & wxFR_WHOLEWORD)
    flags |= wxSTC_FIND_WHOLEWORD;

if (event.GetFlags() & wxFR_MATCHCASE )
    flags |= wxSTC_FIND_MATCHCASE;

int minPos, maxPos;

if (event.GetFlags() & wxFR_DOWN)
{
    minPos = myEditControl->GetCurrentPos();
    maxPos = 0xFFFFF;
}
else
{
    minPos = myEditControl->GetCurrentPos();
    if (minPos)
        minPos--;
    maxPos = 0;
}

int found = myEditControl->FindText(minPos,maxPos,event.GetFindString(),flags);

if (found != -1)
    myEditControl->SetSelection(found, found + event.GetFindString().size());

myEditControl->SetFocus();
