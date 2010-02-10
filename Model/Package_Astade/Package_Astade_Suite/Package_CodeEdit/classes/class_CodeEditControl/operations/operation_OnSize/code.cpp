int x = GetClientSize().x +
        (g_CommonPrefs.lineNumberEnable? m_LineNrMargin: 0) +
        (g_CommonPrefs.foldEnable? m_FoldingMargin: 0);
if (x > 0) SetScrollWidth (x);
event.Skip();
