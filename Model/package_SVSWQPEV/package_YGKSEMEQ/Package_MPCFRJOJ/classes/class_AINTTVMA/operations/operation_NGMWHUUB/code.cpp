if (event.GetMargin() == 2) {
    int lineClick = LineFromPosition (event.GetPosition());
    int levelClick = GetFoldLevel (lineClick);
    if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0) {
        ToggleFold (lineClick);
    }
}
