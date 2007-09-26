int Nr;
int charset = GetCodePage();
switch (event.GetId()) {
    case myID_CHARSETANSI: {charset = wxSTC_CHARSET_ANSI; break;}
    case myID_CHARSETMAC: {charset = wxSTC_CHARSET_ANSI; break;}
}
for (Nr = 0; Nr < wxSTC_STYLE_LASTPREDEFINED; Nr++) {
    StyleSetCharacterSet (Nr, charset);
}
SetCodePage (charset);
