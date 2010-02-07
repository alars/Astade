int eolMode = GetEOLMode();
switch (event.GetId()) {
    case myID_CONVERTCR: { eolMode = wxSTC_EOL_CR; break;}
    case myID_CONVERTCRLF: { eolMode = wxSTC_EOL_CRLF; break;}
    case myID_CONVERTLF: { eolMode = wxSTC_EOL_LF; break;}
}
ConvertEOLs (eolMode);
SetEOLMode (eolMode);
