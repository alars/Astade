//~~ void OnCharAdded(wxStyledTextEvent & event) [CodeEditControl] ~~
char chr = (char)event.GetKey();
int currentLine = GetCurrentLine();
// Change this if support for mac files with \r is needed
if (chr == '\n') {
    int lineInd = 0;
    if (currentLine > 0) {
        lineInd = GetLineIndentation(currentLine - 1);
    }
    if (lineInd == 0) return;
    SetLineIndentation (currentLine, lineInd);
    GotoPos(PositionFromLine (currentLine) + lineInd);
}