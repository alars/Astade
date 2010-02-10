int min = GetCurrentPos ();
int max = BraceMatch (min);
if (max > (min+1)) {
    BraceHighlight (min+1, max);
    SetSelection (min+1, max);
}else{
    BraceBadLight (min);
}
