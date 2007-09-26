switch (event.GetId()) {
    case myID_CHANGELOWER: {
        CmdKeyExecute (wxSTC_CMD_LOWERCASE);
        break;
    }
    case myID_CHANGEUPPER: {
        CmdKeyExecute (wxSTC_CMD_UPPERCASE);
        break;
    }
}
