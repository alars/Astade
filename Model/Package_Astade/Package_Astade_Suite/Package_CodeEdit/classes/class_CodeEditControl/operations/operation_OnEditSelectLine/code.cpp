int lineStart = PositionFromLine (GetCurrentLine());
int lineEnd = PositionFromLine (GetCurrentLine() + 1);
SetSelection (lineStart, lineEnd);
